// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int max_len = 0;
//       for(int i=0;i<s.length();i++){
//           unordered_set<char> st;
//           for(int j=i;j<s.length();j++){
//             if(st.find(s[j])!=st.end()){
//                max_len = max(max_len,j-i);
//                break;
//             }
//             st.insert(s[j]);
//           }
//       }
//       return max_len;
//     }
// };

//sliding window 

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//       int max_len = 0;
//       int initial=0;
//       int final=0;
//       unordered_set<char> st;
//       for(final;final<s.length();final++){
//         if(st.find(s[final])!=st.end()){
//           while(initial<final && st.find(s[final])!=st.end()){
//             st.erase(s[initial]);
//             initial++;
//           }
//         }
//         st.insert(s[final]);
//         max_len = max(max_len,final-initial+1);
//       }
//       return max_len;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int max_len=0;
      int initial=0;
      int final=0;
      int len=0;
      unordered_map<char,int> mp;
      while(final<s.length()){
        if(mp.find(s[final])!=mp.end()){
          initial=max(initial,mp[s[final]]+1);
        }
        mp[s[final]]=final;
        len=max(len,final-initial+1);
        final++;
      }
      return len;
    }
};


int main() {
  string str = "takeaUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << 
  obj.lengthOfLongestSubstring(str);
  return 0;
}