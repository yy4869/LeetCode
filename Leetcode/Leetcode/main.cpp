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
};

int main() {
//    cout << BitCalculate().rangeBitwiseAnd(5, 7) << endl;
    cout << Solution().isMatch("aab", "c*a*b") << endl;;
    cout << Solution().isMatch("aa", "a");
    cout << endl;
}
