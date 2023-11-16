
#include <iostream>
#include<vector>
using namespace std;

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   bool isTreeSame;
public:
  Solution():isTreeSame(true){};
  void preOrder(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL){
      return;
    }
    if(p==NULL || q==NULL){
      isTreeSame=false;
    }
    if(p->val!=q->val){
      isTreeSame=false;
    }
    preOrder(p->left,q->left);
    preOrder(p->right,q->right);
  }
 bool isSameTree(TreeNode* p, TreeNode* q) {
    preOrder(p,q);
    return isTreeSame;
   }
};