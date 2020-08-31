//
//  TreeCalculate.cpp
//  Leetcode
//
//  Created by yaoyuan on 2020/8/31.
//  Copyright © 2020 yaoyuan. All rights reserved.
//

#include "Utils.hpp"


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MyTree {
public:
    TreeNode* root;
    // [1,2,null]
    //   1
    //  / \
    // 2  null
    TreeNode* handleInput(string data) {
        
        return root;
    }
};

// 897. 递增顺序查找树
class Solution_897 {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) {
                out<<tmp->val<<" ";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                out<<"null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) {
            if (val == "null") {
                vec.push_back(NULL);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1;                                          // i每往后移动一位，j移动两位，j始终是当前i的左子下标
        for (int i = 0; j < vec.size(); ++i) {              // 肯定是j先到达边界，所以这里判断j < vec.size()
            if (vec[i] == NULL) continue;                   // vec[i]为null时跳过。
            if (j < vec.size()) vec[i]->left = vec[j++];    // 当前j位置为i的左子树
            if (j < vec.size()) vec[i]->right = vec[j++];   // 当前j位置为i的右子树
        }
        return vec[0];
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
