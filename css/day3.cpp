// A conveyor belt has packages that must be shipped from one port to another within days days.

//     The ith package on the conveyor belt has a weight of weights[i]
//         .Each day,
//     we load the ship with packages on the conveyor belt(in the order given by weights).We may not load more weight than the maximum weight capacity of the ship.

//     Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
   bool isItPossibleToShipWithinGivenDay(vector<int> &weights, int capacity, int days)
   {
      int dayForShip = 1;
      int load = 0;
      for (auto weg : weights)
      {
         if (load + weg > capacity)
         {
            dayForShip++;
            load = weg;
         }
         else
         {
            load += weg;
         }
      }
      return dayForShip <= days;
   }

   int shipWithinDays(vector<int> &weights, int days)
   {
      int low = *max_element(weights.begin(), weights.end());
      int high_capacity = accumulate(weights.begin(), weights.end(), 0);

      while (low <= high_capacity)
      {
         int tem_capacity = (low + high_capacity) / 2;
         if (isItPossibleToShipWithinGivenDay(weights, tem_capacity, days))
         {
            high_capacity = tem_capacity - 1;
         }
         else
         {
            low = tem_capacity + 1;
         }
      }

      return low;
   }
};