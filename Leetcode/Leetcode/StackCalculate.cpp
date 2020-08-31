//
//  StackCalculate.cpp
//  Leetcode
//
//  Created by yaoyuan on 2020/8/28.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"

// 946.验证栈序列
class Solution_946 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        stack<int> s;
        int length = pushed.size();
        int j = 0;
        for (auto x: pushed) {
            s.push(x);
            while (!s.empty() && j < length && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return j == length;
    }
//    输入：pushed = [2,1,0], popped = [1,2,0]
//    输出：true
};

// 841. 钥匙和房间
class Solution_841 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int number = rooms.size();
        bool visited[number];
        memset(visited, false, sizeof(visited));
        visited[0] = true;
        stack<int> roomstack;
        roomstack.push(0);
        while (!roomstack.empty()) {
            int top = roomstack.top();
            roomstack.pop();
            visited[top] = true;
            for (auto key: rooms[top]) {
                if (!visited[key]) {
                    roomstack.push(key);
                }
            }
        }
        for (auto visit: visited) {
            if (!visit) {
                return false;
            }
        }
        return true;
    }
};
