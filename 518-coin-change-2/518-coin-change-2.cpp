// class Solution {
// public:
//     int f(int ind, vector<int> &coins, int tar){
//         if(ind == 0){
//             return tar%coins[0] == 0;
//         }
        
//         int notTake = 0 + f(ind-1, coins, tar);
//         int take = 0;
//         if(coins[ind] <= tar) take = f(ind, coins, tar-coins[ind]);
        
//         return take + notTake;
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return f(n-1, coins, amount);
//     }
// };

//////////////////////////////////Memoization////////////////////////////////
// class Solution {
// public:
//     int f(int ind, vector<int> &coins, int tar, vector<vector<int>> &dp){
//         if(ind == 0){
//             return tar%coins[0] == 0;
//         }
//         if(dp[ind][tar] != -1) return dp[ind][tar];
        
//         int notTake = 0 + f(ind-1, coins, tar, dp);
//         int take = 0;
//         if(coins[ind] <= tar) take = f(ind, coins, tar-coins[ind], dp);
        
//         return dp[ind][tar] = take + notTake;
//     }
    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int> (amount+1,-1));
//         return f(n-1, coins, amount, dp);
//     }
// };

//////////////////////////////////Tabulation////////////////////////////////
// class Solution {
// public:    
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1,0));
        
//         for(int tar = 0; tar<=amount; tar++){
//             if(tar%coins[0] == 0) dp[0][tar] = 1;
//         }
        
//         for(int ind = 1; ind<n; ind++){
//             for(int tar = 0; tar<=amount; tar++){
//                 int notTake = 0 + dp[ind-1][tar];
//                 int take = 0;
//                 if(coins[ind] <= tar) take = dp[ind][tar-coins[ind]];

//                 dp[ind][tar] = take + notTake;
//             }
//         }
        
//         return dp[n-1][amount];
//     }
// };

//////////////////////////////////Space Optimisation////////////////////////////////
class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        
        for(int tar = 0; tar<=amount; tar++){
            if(tar%coins[0] == 0) prev[tar] = 1;
        }
        
        for(int ind = 1; ind<n; ind++){
            for(int tar = 0; tar<=amount; tar++){
                int notTake = 0 + prev[tar];
                int take = 0;
                if(coins[ind] <= tar) take = curr[tar-coins[ind]];

                curr[tar] = take + notTake;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};