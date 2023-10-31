// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// solution

// see can hava a speed of k==1, or k==1000
// let say we have a total banana "total_bananas"
// if let say speed is k, then we have to eat "total_bananas/k" bananas in h hours
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Solution
{
public:
   bool canEatAll(vector<int> &piles, int k, int h)
   {
      int hours = 0;
      for (int pile : piles)
      {
         hours += ceil(static_cast<double>(pile) / static_cast<double>(k));
      }
      return hours <= h;
   }
   int minEatingSpeed(vector<int> &piles, int h)
   {
      int low = 1, high = INT_MIN;
      for (int pile : piles)
      {
         if (pile > high)
         {
            high = pile;
         }
      }
      while (low <= high)
      {
         int med = (low + high) / 2;
         if (canEatAll(piles, med, h))
         {
            high = med - 1;
         }
         else
         {
            low = med + 1;
         }
      }
      return low;
   }
};