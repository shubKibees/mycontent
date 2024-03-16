// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.


#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int byStock(vector<int>& prices,int index,bool canBuy=true){
//       if(index==0)return 0;
//       int profit{0};
//       if(canBuy){
//          int select_Stock=-prices[index]+byStock(prices,index-1,false);
//          int not_Select=byStock(prices,index-1);
//          profit = max(select_Stock,not_Select);
//       }
//       else{
//          int sell_Stock=prices[index]+byStock(prices,index-1);
//          int not_Sell=byStock(prices,index-1,false);
//          profit = max(sell_Stock, not_Sell);
//       }
//       return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//       return byStock(prices,prices.size());
//     }
// };







//memorization


// class Solution{
//   vector<vector<int>>memory;
//   public:
//   int byStock(vector<int>& prices,int index,bool canBuy=true){
//     //base case
//       if(index==prices.size())return 0;
//     //
//     //memorization
//       if(memory[static_cast<int>(canBuy)][index]!=-1){
//         return memory[canBuy][index];
//       }
//     //
//       int profit{0};
//       if(canBuy){
//          int select_Stock=-prices[index]+byStock(prices,index+1,false);
//          int not_Select=byStock(prices,index+1);
//          profit = max(select_Stock,not_Select);
//       }
//       else{
//          int sell_Stock=prices[index]+byStock(prices,index+1);
//          int not_Sell=byStock(prices,index+1,false);
//          profit = max(sell_Stock, not_Sell);
//       }
//       return memory[static_cast<int>(canBuy)][index]=profit;
//     }
//   int maxProfit(vector<int>& prices) {
//       memory.resize(2,vector<int>(prices.size()+1,-1));
//       return byStock(prices,0);
//       };
// };



//tabulation 

class Solution{
  vector<vector<int>>memory;
  public:
    int byStock(vector<int>&prices,int last_index){
      int profit{0};
      for(int x=last_index-1;x>=0;x--){
        for(int y:{0,1}){
          if(y){
            int buy_stock=-prices[x]+memory[0][x+2];
            int _stock=memory[1][x+1];
            profit=max(buy_stock,_stock);
          }
          else{
            int sell_stock=prices[x]+memory[1][x+1];
            int _stock=memory[0][x+1];
            profit=max(sell_stock,_stock);
          }
          memory[y][x]=profit;
        }
      }
      return memory[1][0];
    }
    int maxProfit(vector<int>& prices){
      int last_index=prices.size();
      memory.resize(2,vector<int>(last_index+2,0));
      return byStock(prices,last_index);
    }
};


//space optimization

class Solution {
    int memory[2][2];
public:
    Solution(): memory{{-1, 0}, {-1, 0}} {}

    int byStock(vector<int>& prices, int last_index) {
        memory[1][1] = memory[0][1] = 0;
        int profit = 0;
        for (int x = last_index - 1; x >= 0; x--) {
            for (int y : {0, 1}) {
                if (y) {
                    int buy_stock = -prices[x] + memory[0][1];
                    int _stock = memory[1][1];
                    profit = max(buy_stock, _stock);
                } else {
                    int sell_stock = prices[x] + memory[1][1];
                    int _stock = memory[0][1];
                    profit = max(sell_stock, _stock);
                }
                memory[y][0] = profit;
            }
            memory[0][1] = max(memory[0][0], memory[0][1]); // Update for the next day
            memory[1][1] = max(memory[1][0], memory[1][1]); // Update for the next day
        }
        return memory[1][0];
    }

    int maxProfit(vector<int>& prices) {
        int last_index = prices.size();
        return byStock(prices, last_index);
    }
};


int main(){
  Solution obj;
  vector<int>tt{3,3,5,0,0,3,1,4};
  cout<<obj.maxProfit(tt);
}


