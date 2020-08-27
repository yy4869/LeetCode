//
//  String.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/24.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"

// 459. 重复的子字符串
class Solution_459 {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
    bool isMatch(string s, string p);
};

// 10. 正则表达式匹配
class Solution_10 {
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
    
    // 搞笑解法
    bool isMatch2(string s, string p) {
        string pattern = p;
        regex re(pattern);
        return regex_match(s, re);
    }
};

// 6. Z 字形变换
class Solution_6 {
public:
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
};

// 12. 整数转罗马数字
class Solution_12 {
public:
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

//657. 机器人能否返回原点
class Solution_657 {
public:
    bool judgeCircle(string moves) {
        int vertical = 0, horizon = 0;
        for (auto ch: moves) {
            switch (ch) {
                case 'R':
                    horizon += 1;
                    break;
                case 'L':
                    horizon += -1;
                    break;
                case 'U':
                    vertical += 1;
                    break;
                case 'D':
                    vertical += -1;
                    break;
                default:
                    break;
            }
        }
        return vertical == 0 && horizon == 0;
    }
//    R（右），L（左），U（上）和 D（下）
};
