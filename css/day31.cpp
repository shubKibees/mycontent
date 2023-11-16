
#include<iostream>
#include<vector>
using namespace std;

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.


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
    int height(TreeNode* root,int &max_diameter){
        if(root==NULL){
         return 0;
        }
        int lh=height(root->left,max_diameter);
        int rh=height(root->right,max_diameter);
        max_diameter=max(max_diameter,lh+rh);
        return max(lh,rh)+1;  
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter=0;
        height(root,max_diameter);
        return max_diameter;
    }
};