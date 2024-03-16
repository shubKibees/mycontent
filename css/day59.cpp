// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


#include<iostream>
#include<vector>
using namespace std;


// class Solution1{
//   public:
//   vector<vector<vector<int>>>memory;
//   int byStock(vector<int>& prices,int index,bool canBuy,int clamp){
//     //base case
//       if(index==prices.size() || clamp==0)return 0;
//     //memorization
//       if(memory[static_cast<int>(canBuy)][index][clamp]!=-1){
//         return memory[canBuy][index][clamp];
//       }
//     //
//       int profit{0};
//       if(canBuy){
//          int select_Stock=-prices[index]+byStock(prices,index+1,false,clamp);
//          int not_Select=byStock(prices,index+1,true,clamp);
//          profit = max(select_Stock,not_Select);
//       }
//       else{
//          int sell_Stock=prices[index]+byStock(prices,index+1,true,clamp-1);
//          int not_Sell=byStock(prices,index+1,false,clamp);
//          profit = max(sell_Stock, not_Sell);
//       }
//       return memory[static_cast<int>(canBuy)][index][clamp]=profit;
//     }
//   int maxProfit(vector<int>& prices) {
//       memory.resize(2,vector<vector<int>>(prices.size()+1,vector<int>{-1,-1,-1}));
//       return byStock(prices,0,true,2);
//       };
// };


//tabulation 


class Solution {
    vector<vector<vector<int>>> memory;
public:
    int byStock(vector<int>& prices, int price_size) {
        int profit = 0;
        for (int x = price_size - 1; x >= 0; x--) {
            for (int canBuy : {0, 1}) {
                for (int clamp : {1, 2}) {
                    if (canBuy) {
                        int buy_stock = -prices[x] + memory[0][x + 1][clamp];
                        int _stock = memory[1][x + 1][clamp];
                        profit = max(buy_stock, _stock);
                    } else {
                        int sell_stock = prices[x] + memory[1][x + 1][clamp - 1];
                        int _stock = memory[0][x + 1][clamp];
                        profit = max(sell_stock, _stock);
                    }
                    memory[canBuy][x][clamp] = profit;
                }
            }
        }
        return memory[1][0][2]; 
    }

    int maxProfit(vector<int>& prices) {
        int price_size = prices.size();
        memory.resize(2, vector<vector<int>>(price_size + 1, vector<int>{0,0,0}));
        auto mem=byStock(prices, price_size);
        return mem;
    }
    
};



int main(){
  Solution obj;
  vector<int>tt{3,3,5,0,0,3,1,4};
  cout<<obj.maxProfit(tt);
}














