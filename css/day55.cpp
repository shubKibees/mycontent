// In this article, we will solve the most asked coding interview problem: Grid Unique Paths

// Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).

// At any cell we are allowed to move in only two directions:- bottom and right.


#include <iostream>
#include<vector>
using namespace std;


// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//       //base case
//       if(n==1 || m==1){
//          return 1;
//       }
//       //total uniquePaths
//       int total_paths=uniquePaths(m-1,n) + uniquePaths(m,n-1);
//       return total_paths;
//     }
// };

//memorization way

// #include <vector>
// using namespace std;

// class Solution {
//     vector<vector<int>> memory;
// public:
//     int totalUniquePath(int m, int n) {
//         if (n == 1 || m == 1) {
//             return 1;
//         }
//         // memory condition
//         if (memory[m][n] != -1) {
//             return memory[m][n];
//         }
//         // total uniquePaths
//         int total_paths = totalUniquePath(m - 1, n) + totalUniquePath(m, n - 1);
//         return memory[m][n] = total_paths;
//     }

//     int uniquePaths(int m, int n) {
//         memory.resize(m + 1, vector<int>(n + 1, -1));
//         return totalUniquePath(m, n);
//     }
// };

// lets do tabulation approch

class Solution{
   vector<vector<int>> memory;
   public:
     void totalUniquePath(int m, int n){
      //initialization
      for(int x{1};x<=m;x++){
        memory[x][1]=1;
      }
      for(int y{1};y<=n;y++){
        memory[1][y]=1;
      }      
      for(auto x_arra:memory){
        for(auto y:x_arra){
          cout<<y<<" ";
        }
        cout<<endl;
      }
      // for(int y{2};y<=m;y++){
      //   for(int x{2};x<=n;x++){
      //     memory[y][x]=memory[y-1][x]+memory[y][x-1];
      //   }
      // }
      // return memory[m][n];
     }
     //initialize the memory
     void uniquePaths(int m, int n) {
        memory.resize(m + 1, vector<int>(n + 1, 0));
        return totalUniquePath(m, n);
    }
};


int main(){
  Solution obj;
  obj.uniquePaths(3,3);
}