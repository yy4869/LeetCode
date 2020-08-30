//
//  ListCalculate.cpp
//  Leetcode
//
//  Created by yaoyuan on 2020/8/28.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"
//
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution_List {
public:
    ListNode* handleInput(vector<int> array) {
        if (array.size() <= 0) return NULL;
        ListNode *head, *cur;
        cur = new ListNode(array[0]);
        head = cur;
        for (int i = 1; i < array.size(); i++) {
            ListNode *temp = new ListNode(array[i]);
            cur -> next = temp;
            cur = temp;
        }
        cur -> next = NULL;
        return head;
    }
    
    void handleOutput(ListNode* head) {
        while (head != NULL) {
            cout << head -> val << " ";
            head = head -> next;
        }
        cout << endl;
    }
};

// 19. 删除链表的倒数第N个节点
class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head, *pre = head;
        while (n-- > 0) {
            fast = fast -> next;
        }
        while (fast != NULL) {
            pre = slow;
            fast = fast -> next;
            slow = slow -> next;
        }
        if (slow == head) {
            return head -> next;
        } else {
            pre -> next = slow -> next;
            return head;
        }
    }

    void validate(vector<int> array, int n) {
        ListNode *head = Solution_List().handleInput(array);
        Solution_List().handleOutput(removeNthFromEnd(head, n));
    }
};
