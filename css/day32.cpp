




#include <iostream>
#include<vector>
using namespace std;

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int findMaxPathSum(TreeNode* root,int &max_value){
      if(root == NULL){
         return 0;
      }
      int left = max(0,findMaxPathSum(root->left, max_value));
      int right = max(0,findMaxPathSum(root->right, max_value));
      int value = root->val; 
      max_value = max(max_value, left+right+value); 
      return (max(left,right)+value);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};