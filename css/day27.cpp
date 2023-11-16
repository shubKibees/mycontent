
// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// preorder     node left right

#include<iostream>
#include<vector>
#include<stack>
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
    void preorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
         return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
   void inorder(TreeNode* root,vector<int>&ans){
      if(root==NULL){
         return;
      }
      inorder(root->left,ans);
      ans.push_back(root->val);
      inorder(root->right,ans);
   }
   vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      inorder(root,ans);
      return ans;
   }
   void postorder(TreeNode* root,vector<int>&ans){
      if(root==NULL){
         return;
      }
      postorder(root->left,ans);
      postorder(root->right,ans);
      ans.push_back(root->val);
   }
   vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
      postorder(root,ans);
      return ans;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==NULL){
         return ans;
      }
      stack<TreeNode*> st;
      st.push(root);
      while(!st.empty()){
         TreeNode* temp = st.top();
         ans.push_back(temp->val);
         st.pop();
         if(temp->right){
            st.push(temp->right);
         }
         if(temp->left){
            st.push(temp->left);
         }
      }
      return ans;
    }
};