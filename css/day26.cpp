//binary treee
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int data_):data(data_),left(nullptr),right(nullptr){}
    Node(int data_, Node* left, Node* right):data(data_),left(left),right(right){}
};

Node* createTree(vector<int>&arr){
    Node* root = new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    int index = 0;
    while(index<arr.size()){
      int left = 2*index+1;
      int right = 2*index+2;
      Node *currect=q.front();
      q.pop();
      if(left<arr.size()){
          currect->left = new Node(arr[left]);
          q.push(currect->left);
      }
      if(right<arr.size()){
         currect->right = new Node(arr[right]);
         q.push(currect->right);
      }
      index++;
    }
    return root;
};


// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> preorder;
//         stack<TreeNode*> stack;
//         if (root == NULL)
//             return preorder;
//         stack.push(root);
//         while(!stack.empty()) {
//             TreeNode* curr = stack.top();
//             stack.pop();
//             preorder.push_back(curr->val);
//             if (curr->right != NULL)
//                 stack.push(curr->right);
//             if (curr->left != NULL)
//                 stack.push(curr->left);
//         }
//         return preorder;
//     }
// };
