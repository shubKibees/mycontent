// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    vector<vector<int>> ans;

public:
    void bfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int size_ = q.size();
            for (int i(0); i < size_; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        for (int i = 0; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
