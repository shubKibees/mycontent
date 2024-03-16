#include<iostream>
#include<vector>
using namespace std;

class Solution{
  vector<vector<int>>memory;
  public:
    int byStock(vector<int>&prices,int last_index,int fee){
      int profit{0};
      for(int x=last_index-1;x>=0;x--){
        for(int y:{0,1}){
          if(y){
            int buy_stock=-prices[x]+memory[0][x+1];
            int _stock=memory[1][x+1];
            profit=max(buy_stock,_stock);
          }
          else{
            int sell_stock=prices[x]-fee+memory[1][x+2];
            int _stock=memory[0][x+1];
            profit=max(sell_stock,_stock);
          }
          memory[y][x]=profit;
        }
      }
      return memory[1][0];
    }
    int maxProfit(vector<int>& prices,int fee){
      int last_index=prices.size();
      memory.resize(2,vector<int>(last_index+2,0));
      return byStock(prices,last_index,fee);
};
}

int main(){
   vector<int>prices{4, 9, 0, 4, 10};
   Solution s;
   cout<<s.maxProfit(prices,2);
}