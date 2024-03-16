#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if (ind == n || cap == 0)
        return 0;

    // If the result is already calculated, return it.
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
                     -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
                     Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
    }

    // Store and return the calculated profit.
    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector<int>& prices, int n) {
    // Creating a 3D DP array of size [n][2][3]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    // Call the recursive function to calculate maximum profit
    return getAns(prices, n, 0, 0, 2, dp);
}

int main() {
    vector<int> prices = {2,1,4,5,2,9,7};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
