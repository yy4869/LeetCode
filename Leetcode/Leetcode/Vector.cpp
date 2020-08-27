//
//  Vector.cpp
//  Leetcode
//
//  Created by 媛小仙女 on 2020/8/27.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"

// 4. 寻找两个正序数组的中位数
// 要求算法的时间复杂度为 O(log(m + n))。
class Solution_4_findMedianSortedArrays {
public:
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
};
