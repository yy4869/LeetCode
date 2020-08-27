//
//  String.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/24.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "String.hpp"
#include <regex>

// 459. 重复的子字符串
bool String::repeatedSubstringPattern(string s) {
    return (s + s).find(s, 1) != s.size();
}

// 10. 正则表达式匹配
bool String::isMatch(string s, string p) {
//    int sl = (int)s.length(), pl = (int)p.length();
//    for (int i = sl - 1, j = pl - 1; i >= 0; ) {
//        if (s[i] == p[j]) {
//            i--;
//            j--;
//        } else if (p[j] == '*') {
//
//        }
//    }
    // 搞笑解法
//    string pattern = p;
//    regex re(pattern);
//    return regex_match(s, re);
    return true;
}
//s = "aa"
//p = "a*"
//输出: true
