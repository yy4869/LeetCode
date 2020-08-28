//
//  DP.cpp
//  Leetcode
//
//  Created by yaoyuan on 2020/8/28.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include <stdio.h>
#include "Utils.hpp"

// 754. 到达终点数字
class Solution_754 {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) {
            k += 1;
            target -= k;
        }
        return target % 2 == 0 ? k : k + 1 + k % 2;
    }
};
