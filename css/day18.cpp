// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

//     Trie() Initializes the trie object.
//     void insert(String word) Inserts the string word into the trie.
//     boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
//     boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
   public:
   unordered_map<char,Node*> children;
   bool endOfWord;
   Node():endOfWord{false}{
     }
};


class Trie {
    Node* root;
public:
    Trie() {
      root=new Node();
    }
    
    void insert(string word) {
      Node* temp=root;
      for(char c:word){
          if(temp->children.find(c)==temp->children.end()){
              temp->children[c]=new Node();
          }
          temp=temp->children[c];
      }
      temp->endOfWord=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(char c:word){
         if(temp->children.find(c)==temp->children.end()){
            return false;
         }
         temp=temp->children[c];
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(char c:prefix){
         if(temp->children.find(c)==temp->children.end()){
            return false;
         }
         temp=temp->children[c];
        }
        return true;
    }
};
