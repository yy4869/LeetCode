//
//  BitCalculate.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/23.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "BitCalculate.hpp"

// 201. 数字范围按位与
int BitCalculate::rangeBitwiseAnd(int m, int n) {
    int count = 0;
    for (; m != n; count++) {
        m >>= 1;
        n >>= 1;
    }
    return m <<= count;
}

// test
