// class Solution {
// public:
//     int f(int ind, int buy, int n, vector<int> &arr,vector<vector<int>> &dp, int fee){
//         if(ind == n) return 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         int profit = 0;
        
//         if(buy){
//             int take = -arr[ind] + f(ind+1,0,n,arr,dp,fee);
//             int notTake = 0 + f(ind+1,1,n,arr,dp,fee);
//             profit = max(take,notTake);
//         }
//         else{
//             int sell = arr[ind] - fee + f(ind+1,1,n,arr,dp,fee);
//             int notsell = 0 + f(ind+1,0,n,arr,dp,fee);
//             profit = max(sell,notsell);
//         }
        
//         return dp[ind][buy] = profit;
//     }
    
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1)); //2 bcoz we can buy or sell
        
//         return f(0,1,n,prices,dp,fee);
//     }
// };

//////////////////////////Tabulation////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                int profit = 0;
        
                if(buy){
                    int take = -prices[ind] + dp[ind+1][0];
                    int notTake = 0 + dp[ind+1][1];
                    profit = max(take,notTake);
                }
                else{
                    int sell = prices[ind] - fee + dp[ind+1][1];
                    int notsell = 0 + dp[ind+1][0];
                    profit = max(sell,notsell);
                }

                dp[ind][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};