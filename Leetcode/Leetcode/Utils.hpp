//
//  Utils.hpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/24.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

template <class T, class A>
T join(const A &begin, const A &end, const T &t);

vector<string>  split(const string& str,const string& delim);
string reverse_one_word(string str);
string trim(string &s);
string toUpper(string &str);
string toLower(string &str);
string eraseSpace(string &str);
string eraseByCodition(string &str);
string replaceByStr(string &str, string from, string desc);
bool startWith(string str, string head);
bool endWith(string str, string tail);
string concat(vector<string> arrays);

#endif /* Utils_hpp */
