

#include<iostream>   
#include<vector>
#include<queue>
using namespace std;

// Given a binary tree, determine if it is
// height-balanced.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    pair<int,bool> height_balance(TreeNode* root) {
        if (root == NULL){
         return {0,true};
        }
        pair<int,bool>left = height_balance(root->left);
        pair<int,bool>right = height_balance(root->right);
        int height = max(left.first,right.first)+1;
        if(abs(left.first-right.first)>1){
            return {height,false};
        }
        return {height,left.second&&right.second};
    }
    bool isBalanced(TreeNode* root) {
        return height_balance(root).second;
    }
};