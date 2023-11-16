#include<iostream>
#include<vector>
#include<queue>
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
public:
    void level_Order(TreeNode* root,vector<int>& ans){
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty())
      {
         TreeNode* temp = q.front();
         q.pop();
         ans.push_back(temp->val);
         if(temp->left!=NULL) q.push(temp->left);
         if(temp->right!=NULL) q.push(temp->right);
      }
    }
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        level_Order(root,ans);
        return ans;
    }
};