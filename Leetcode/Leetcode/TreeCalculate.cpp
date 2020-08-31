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

// 参考leetcode输入和建树的方式
// [1,2,null]
//   1
//  / \
// 2  null
class MyTree {
public:
    string data;
    TreeNode* root;
    vector<string> nodes;
    MyTree(string data): data(data) {
        handleLeetcodeTreeInputString(data);
        root = deserialize();
    }

    void handleLeetcodeTreeInputString(string data) {
        // string data = "[1,2, 3,null ] ";
        trim(data);
        data.erase(data.begin());
        data.erase(data.end() - 1);
        eraseSpace(data);
        nodes = split(data, ",");
        // {1,2,3,null}
        // cout << concat(split(data, ","));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize() {
        vector<TreeNode*> vec;
        for (auto val: nodes) {
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

    // Encodes a tree to a single string.
    string serialize() {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) {
                if (res.length() != 0) {
                    res += ",";
                }
                res += to_string(tmp -> val);
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                if (res.length() != 0) {
                    res += ",";
                }
                res += "null";
            }
        }
        return "[" + res + "]";
    }
};

// 897. 递增顺序查找树
class Solution_897 {
public:
    void run() {
        TreeNode* root;
        increasingBST(root);
    }
    TreeNode* increasingBST(TreeNode* root) {
//        string data = "[5,3,6,2,4,null,8,1,null,null,null,7,9]";
//        MyTree *mytree = new MyTree(data);
//        cout << mytree -> serialize() << endl;
        TreeNode *cur = root;
        return root;
    }
};
//输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \
//1        7   9
//
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9
//
