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
class Solution {
public:
    int f(int ind, vector<int> &coins, int tar, vector<vector<int>> &dp){
        if(ind == 0){
            return tar%coins[0] == 0;
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int notTake = 0 + f(ind-1, coins, tar, dp);
        int take = 0;
        if(coins[ind] <= tar) take = f(ind, coins, tar-coins[ind], dp);
        
        return dp[ind][tar] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return f(n-1, coins, amount, dp);
    }
};