//
//  main.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/23.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "BitCalculate.hpp"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m = s.size(), n = p.size();
        bool dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[m][n];
    }


    map<char, string> digitToStr = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        letterCombination(digits, 0);
        return res;
    }

    void letterCombination(string digits, int loc) {
        if (loc == digits.size()) {
            return;
        }
        char key = digits[loc];
        string values = digitToStr[key];

        if (loc == 0) {
            for (int i = 0; i < values.size(); i++) {
                res.push_back(string(1, values[i]));
            }
        } else {
            vector<string> temp = res;
            // 扩容n - 1倍
            for (int i = 0; i < values.size() - 1; i++) {
                res.insert(res.end(), temp.begin(), temp.end());
            }

            int time = res.size() / values.size();
            for (int i = 0; i < values.size(); i++) {
                for (int j = 0; j < time; j++) {
                    res[i * time + j] += values[i];
                }
            }
        }
        letterCombination(digits, loc + 1);
    }
};

int main() {
//    cout << BitCalculate().rangeBitwiseAnd(5, 7) << endl;
//    cout << Solution().isMatch("aab", "c*a*b") << endl;;
//    cout << Solution().isMatch("aa", "a");
    vector<string> res = Solution().letterCombinations("23");
    for (auto &subStr: res) {
        cout << subStr << endl;
    }
    cout << endl;
}
