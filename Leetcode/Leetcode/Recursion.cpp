//
//  Recursion.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/27.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"

// 17. 电话号码的字母组合
class Solution_17_letterCombinations {
public:
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

