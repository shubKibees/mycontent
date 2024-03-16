// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    double myPowfunction(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if(n<0){
         x=1/x;
        }
        if(n%2==0){
         return myPow(x*x, (n/2));
        }
        else{
         return x*myPow(x, (n/2));
        }
    }
    double myPow(double x, int n) {
      double ans=myPowfunction(x,n);
      return 
    }
   
};
