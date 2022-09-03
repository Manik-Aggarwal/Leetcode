class Solution {
public:
    int f(int ind, int buy, int n, vector<int> &arr,vector<vector<vector<int>>> &dp, int limit){
        if(ind == n) return 0;
        if(limit == 0) return 0;
        if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
        int profit = 0;
        
        if(buy){
            int take = -arr[ind] + f(ind+1,0,n,arr,dp,limit);
            int notTake = 0 + f(ind+1,1,n,arr,dp,limit);
            profit = max(take,notTake);
        }
        else{
            int sell = arr[ind] + f(ind+1,1,n,arr,dp,limit-1);
            int notsell = 0 + f(ind+1,0,n,arr,dp,limit);
            profit = max(sell,notsell);
        }
        
        return dp[ind][buy][limit] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k+1,-1)));
        
        
        return f(0,1,n,prices,dp,k);
    }
};