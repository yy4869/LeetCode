//
//  List.cpp
//  Leetcode
//
//  Created by yaoyuan on 2020/8/28.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include <stdio.h>
#include "Utils.hpp"

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


void handleInput(vector<int> array) {

}

void validateOutput() {

}

// 19. 删除链表的倒数第N个节点
class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        while (n-- > 0) {
            fast = fast -> next;
            cout << fast -> val << endl;
        }
        while (fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
            cout << fast -> val << " " << slow -> val << endl;
        }
        return slow;
    }

    void handleInput(vector<int> array) {
        
    }

    void validateOutput() {

    }
};
