// You are given a string s and an integer temp_k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.
// AABABBA

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// brute force
class Solution
{
public:
   int characterReplacement(string s, int k)
   {
      unordered_set<char> set;
      int max_len=0;
      for (auto ch : s)
      {
         set.insert(ch);
      }
      for (auto ch : set)
      {
         int start = 0;
         int final_iteratior = 0;
         int temp_k = k;
         for (final_iteratior; final_iteratior < s.size(); final_iteratior++)
         {
            if (s[final_iteratior] != ch && temp_k)
            {
               temp_k--;
            }
            else if (s[final_iteratior] != ch && !temp_k)
            {
               while (s[start] == ch)
               {
                  start++;
               }
               start++;
            }
            max_len = max(max_len, final_iteratior - start + 1);
         }
      }
      return max_len;
   }
};

int main()
{
   Solution s;
   string s1 = "AABBAAAAAABBA";
   int k = 2;
   cout << s.characterReplacement(s1, k);
}