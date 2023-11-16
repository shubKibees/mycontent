// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
// class Solution {
// public:
//     int findContentChildren(vector<int>& boxSize, vector<int>& cookieSize) {
//       sort(boxSize.begin(),boxSize.end(),greater<int>());
//       boxSize.push_back(0);
//       sort(cookieSize.begin(),cookieSize.end());
//       int count=0;
//       for(auto cookieSiz:cookieSize){
//          for(int boxSiz=0;boxSiz<boxSize.size();boxSiz++){
//             if(boxSize[boxSiz+1]>cookieSiz||boxSize[boxSiz]==cookieSiz){
//                boxSize[boxSiz]=INT_MAX;
//                break;
//             }
//          }
//       }
//       for(auto boxSiz:boxSize){
//          if(boxSiz==INT_MAX){
//             count++;
//          }
//       }
//       return count-1;
//     }
// };

//{
class Solution {
public:
    int findContentChildren(vector<int>& boxSize, vector<int>& cookieSize) {
      sort(boxSize.begin(),boxSize.end());
      sort(cookieSize.begin(),cookieSize.end());
      int count=0;
      int boxSiz=0;
      int cookieSiz=0;
      while(boxSiz<boxSize.size()&&cookieSiz<cookieSize.size()){
         if(boxSize[boxSiz]<=cookieSize[cookieSiz]){
            boxSiz++;
            count++;
         }
         cookieSiz++;
      }
      return count;
    }
};
//}

int main(){
   Solution s;
   vector<int> boxSize={1,2,3};
   vector<int> cookieSize={3};
   cout<<s.findContentChildren(boxSize,cookieSize);
}