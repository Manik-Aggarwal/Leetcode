// class Solution {
// public:
//     int f(int ind, vector<int> &coins, int tar){
//         if(ind == 0){
//             if(tar%coins[0] == 0) return tar/coins[0];
//             else return 1e9;
//         }
        
//         int notTake = 0 + f(ind-1, coins, tar);
//         int take = 1e9;
//         if(coins[ind] <= tar) take = 1 + f(ind, coins, tar-coins[ind]);
        
//         return min(take, notTake);
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
        
//         int ans = f(n-1, coins, amount);
//         if(ans >= 1e9) return -1;
//         else return ans;
//     }
// };


//////////////////////////////////Memoization//////////////////////////////////
// class Solution {
// public:
//     int f(int ind, vector<int> &coins, int tar, vector<vector<int>> &dp){
//         if(ind == 0){
//             if(tar%coins[0] == 0) return tar/coins[0];
//             else return 1e9;
//         }
//         if(dp[ind][tar] != -1) return dp[ind][tar];
        
//         int notTake = 0 + f(ind-1, coins, tar,dp);
//         int take = 1e9;
//         if(coins[ind] <= tar) take = 1 + f(ind, coins, tar-coins[ind],dp);
        
//         return dp[ind][tar] = min(take, notTake);
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        
//         int ans = f(n-1, coins, amount,dp);
//         if(ans >= 1e9) return -1;
//         else return ans;
//     }
// };

///////////////////////////////Tabulation////////////////////////////////////////
// class Solution {
// public:    
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1,0));
        
//         for(int tar = 0; tar<=amount; tar++){
//             if(tar%coins[0] == 0) dp[0][tar] = tar/coins[0];
//             else dp[0][tar] = 1e9;
//         }
        
//         for(int ind = 1; ind<n; ind++){
//             for(int tar = 0; tar<=amount; tar++){
//                 int notTake = 0 + dp[ind-1][tar];
//                 int take = 1e9;
//                 if(coins[ind] <= tar) take = 1 + dp[ind][tar-coins[ind]];

//                 dp[ind][tar] = min(take, notTake);
//             }
//         }
        
//         int ans = dp[n-1][amount];
//         if(ans >= 1e9) return -1;
//         else return ans;
//     }
// };

///////////////////////////////////Space Optimisation////////////////////////////
class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1.0);
        
        for(int tar = 0; tar<=amount; tar++){
            if(tar%coins[0] == 0) prev[tar] = tar/coins[0];
            else prev[tar] = 1e9;
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int tar = 0; tar<=amount; tar++){
                int notTake = 0 + prev[tar];
                int take = 1e9;
                if(coins[ind] <= tar) take = 1 + curr[tar-coins[ind]];

                curr[tar] = min(take, notTake);
            }
            prev = curr;
        }
        
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};