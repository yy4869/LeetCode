//
//  Utils.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/24.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"
 
int test_regex_match()
{
    std::string pattern{ "\\d{3}-\\d{8}|\\d{4}-\\d{7}" }; // fixed telephone
    std::regex re(pattern);
 
    std::vector<std::string> str{ "010-12345678", "0319-9876543", "021-123456789"};
 
    /* std::regex_match:
        判断一个正则表达式(参数re)是否匹配整个字符序列str,它主要用于验证文本
        注意，这个正则表达式必须匹配被分析串的全部，否则返回false;如果整个序列被成功匹配，返回true
    */
 
    for (auto tmp : str) {
        bool ret = std::regex_match(tmp, re);
        if (ret) fprintf(stderr, "%s, can match\n", tmp.c_str());
        else fprintf(stderr, "%s, can not match\n", tmp.c_str());
    }
 
    return 0;
}
 
int test_regex_search()
{
    std::string pattern{ "http|hppts://\\w*$" }; // url
    std::regex re(pattern);
 
    std::vector<std::string> str{ "http://blog.csdn.net/fengbingchun", "https://github.com/fengbingchun",
        "abcd://124.456", "abcd https://github.com/fengbingchun 123" };
 
    /* std::regex_search:
        类似于regex_match,但它不要求整个字符序列完全匹配
        可以用regex_search来查找输入中的一个子序列，该子序列匹配正则表达式re
    */
 
    for (auto tmp : str) {
        bool ret = std::regex_search(tmp, re);
        if (ret) fprintf(stderr, "%s, can search\n", tmp.c_str());
        else fprintf(stderr, "%s, can not search\n", tmp.c_str());
    }
 
    return 0;
}
 
int test_regex_search2()
{
    std::string pattern{ "[a-zA-z]+://[^\\s]*" }; // url
    std::regex re(pattern);
 
    std::string str{ "my csdn blog addr is: http://blog.csdn.net/fengbingchun , my github addr is: https://github.com/fengbingchun " };
    std::smatch results;
    while (std::regex_search(str, results, re)) {
        for (auto x : results)
            std::cout << x << " ";
        std::cout << std::endl;
        str = results.suffix().str();
    }
 
    return 0;
}
 
int test_regex_replace()
{
    std::string pattern{ "\\d{18}|\\d{17}X" }; // id card
    std::regex re(pattern);
 
    std::vector<std::string> str{ "123456789012345678", "abcd123456789012345678efgh",
        "abcdefbg", "12345678901234567X" };
    std::string fmt{ "********" };
 
    /* std::regex_replace:
        在整个字符序列中查找正则表达式re的所有匹配
        这个算法每次成功匹配后，就根据参数fmt对匹配字符串进行替换
    */
 
    for (auto tmp : str) {
        std::string ret = std::regex_replace(tmp, re, fmt);
        fprintf(stderr, "src: %s, dst: %s\n", tmp.c_str(), ret.c_str());
    }
 
    return 0;
}
 
int test_regex_replace2()
{
    // reference: http://www.cplusplus.com/reference/regex/regex_replace/
    std::string s("there is a subsequence in the string\n");
    std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"
 
    // using string/c-string (3) version:
    std::cout << std::regex_replace(s, e, "sub-$2");
 
    // using range/c-string (6) version:
    std::string result;
    std::regex_replace(std::back_inserter(result), s.begin(), s.end(), e, "$2");
    std::cout << result;
 
    // with flags:
    std::cout << std::regex_replace(s, e, "$1 and $2", std::regex_constants::format_no_copy);
    std::cout << std::endl;
 
    return 0;
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

//将分割后的子字符串存储在vector中
vector<string> split(const string& str,const string& delim) {
    vector<string> res;
    if("" == str) return  res;
    
    string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
    size_t pos;
    size_t size = strs.size();
 
    for (int i = 0; i < size; ++i) {
        pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
        if( pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
            string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
            if (s != "") {
                res.push_back(s); //两个连续delim之间切割出的字符串为空字符串，这里判断s是否为要删除的字符串,最后的结果中没有空字符的输出，
            }
            i = pos + delim.size() - 1;
        }
        
    }
    return res;
}

// 反转字符串
string reverse_one_word(string str) {
    for(int i = 0; i < str.length() / 2; i++) {
        char tmp;
        tmp = str[i];
        str[i] = str[ str.length() - i - 1 ];
        str[str.length() - i - 1] = tmp;
    }
    return str;
}

// 去除字符串前后空格
string trim(string &s) {
    if (s.empty()) return s;
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

// 字符串变成大写
string toUpper(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// 字符串变成小写
string toLower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// 删除字符串中空格
string eraseSpace(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// 按条件删除字符串中所有满足条件的字符
// 只是给个例子
string eraseByCodition(string &str) {
    str.erase(remove_if(str.begin(),
                        str.end(),
                        [](char x) {
                            return isspace(x) || x == 's';
                        }),
              str.end());
    return str;
}

// 用给定字符串 desc 替换原串 str 中的子串 from
string replaceByStr(string &str, string from, string desc) {
    str.replace(str.find(from), from.size(), desc);
    return str;
}

// 判断字符串是否以head开头
bool startWith(string str, string head) {
    return str.compare(0, head.size(), head) == 0;
}

// 判断字符串是否以tail开头
bool endWith(string str, string tail) {
    return str.compare(str.size() - tail.size(), tail.size(), tail) == 0;
}

// 字符串连接
string concat(vector<string> arrays) {
    return accumulate(arrays.begin() , arrays.end() , string(""));
}

// vector按任意字符连接见上方join方法

// std自带的已经实现的比较好的接口：
void test() {
    string str = "i,like,,cat";

    // 字符串中替换所有的某个字符
    replace(str.begin(),str.end(),',',' ');
    // cout:i like  cat

    // 原地翻转字符串
    reverse(str.begin(), str.end());
    // cout:tac  ekil i
}
