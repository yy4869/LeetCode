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
#include "String.hpp"

using namespace std;
#define STOP "#"

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

    // 4. 寻找两个正序数组的中位数
    // 要求算法的时间复杂度为 O(log(m + n))。
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        auto iter1 = nums1.begin(), iter2 = nums2.begin();
        for (; iter1 != nums1.end() && iter2 != nums2.end(); ) {
            if (*iter1 <= *iter2) {
                merged.push_back(*(iter1++));
            } else {
                merged.push_back(*(iter2++));
            }
        }
        if (iter1 != nums1.end()) {
            merged.insert(merged.end(), iter1, nums1.end());
        }
        if (iter2 != nums2.end()) {
            merged.insert(merged.end(), iter2, nums2.end());
        }
        int mid = merged.size() / 2;
        return merged.size() % 2 == 0 ? (double)(merged[mid] + merged[mid - 1]) / 2 : merged[mid];
    }

    // 找第k小的元素
    double findTheKthMinNumber(vector<int> nums1, vector<int> nums2, int k) {
        return 0;
    }


    map<string, string> startToEnd;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        return {};
    }

    void handleInput(vector<vector<string>> tickets) {

    }

    string convert(string s, int numRows) {
        if (s.length() <= 1 || numRows <= 1) {
            return s;
        }
        vector<string> rowline(numRows, "");
        int runloop = numRows * 2 - 2;
        for (int i = 0, mod = 0; i < s.length(); i++) {
            mod = i % runloop;
            if (mod < numRows) {
                rowline[mod] += s[i];
            } else {
                rowline[runloop - mod] += s[i];
            }
        }
        string res = join(rowline.begin(), rowline.end(), string(""));
        return res;
    }

    template <class T, class A>
    T join(const A &begin, const A &end, const T &t) {
        T result;
        for (A it = begin; it != end; it++) {
            if (!result.empty())
                result.append(t);
            result.append(*it);
          }
          return result;
    }

    // 12. 整数转罗马数字
    string intToRoman(int num) {
        vector<pair<int, string>> rule = {
            {1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"},
            {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"}
        };
        string res = "";
        int remain = num;
        int minus;
        for (int i = rule.size() - 1; i >= 0 && remain > 0; i--) {
            minus = remain / rule[i].first;
            for (int j = 0; j < minus ; j++) {
                res += rule[i].second;
            }
            remain -= minus * rule[i].first;
        }
        return res;
    }
};

int main() {
    string res = Solution().intToRoman(1994);
    cout << res << "    " << (res == "MCMXCIV") << endl;
    cout << (Solution().intToRoman(3999) == "MMMCMXCIX") << endl;
    cout << (Solution().intToRoman(2001) == "MMI") << endl;


    /*=========*/
    cout << endl;
//    cout << BitCalculate().rangeBitwiseAnd(5, 7) << endl;
    cout << String().isMatch("aa", "a") << endl; //false
    cout << String().isMatch("aa", "a*") << endl;
    cout << String().isMatch("ab", ".*") << endl;
    cout << String().isMatch("aab", "c*a*b") << endl;
    cout << String().isMatch("mississippi", "mis*is*p*.") << endl; //false
}
