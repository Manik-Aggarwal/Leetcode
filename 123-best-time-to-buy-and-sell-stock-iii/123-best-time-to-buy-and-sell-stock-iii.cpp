// class Solution {
// public:
//     int f(int ind, int buy, int n, vector<int> &arr,vector<vector<vector<int>>> &dp, int limit){
//         if(ind == n) return 0;
//         if(limit == 0) return 0;
//         if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
//         int profit = 0;
        
//         if(buy){
//             int take = -arr[ind] + f(ind+1,0,n,arr,dp,limit);
//             int notTake = 0 + f(ind+1,1,n,arr,dp,limit);
//             profit = max(take,notTake);
//         }
//         else{
//             int sell = arr[ind] + f(ind+1,1,n,arr,dp,limit-1);
//             int notsell = 0 + f(ind+1,0,n,arr,dp,limit);
//             profit = max(sell,notsell);
//         }
        
//         return dp[ind][buy][limit] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int limit = 2;
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        
        
//         return f(0,1,n,prices,dp,limit);
//     }
// };

////////////////////////////Tabulation////////////////////////////////
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
        
//         for(int ind = n-1; ind>=0; ind--){
//             for(int buy=0; buy<2; buy++){
//                 for(int cap=1; cap<3; cap++){
//                     int profit = 0;

//                     if(buy){
//                         int take = -prices[ind] + dp[ind+1][0][cap];
//                         int notTake = 0 + dp[ind+1][1][cap];
//                         profit = max(take,notTake);
//                     }
//                     else{
//                         int sell = prices[ind] + dp[ind+1][1][cap-1];
//                         int notsell = 0 + dp[ind+1][0][cap];
//                         profit = max(sell,notsell);
//                     }
                    
//                     dp[ind][buy][cap] = profit;
//                 }
//             }
//         }
        
//         return dp[0][1][2];
//     }
// };

 //////////////////////////Space Optimisation////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<3; cap++){
                    int profit = 0;

                    if(buy){
                        int take = -prices[ind] + ahead[0][cap];
                        int notTake = 0 + ahead[1][cap];
                        profit = max(take,notTake);
                    }
                    else{
                        int sell = prices[ind] + ahead[1][cap-1];
                        int notsell = 0 + ahead[0][cap];
                        profit = max(sell,notsell);
                    }
                    
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        
        return curr[1][2];
    }
};