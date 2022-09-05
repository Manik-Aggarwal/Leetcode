class Solution {
public:
    int f(int ind, int buy, int n, vector<int> &arr,vector<vector<int>> &dp){
        if(ind >= n) return 0;//if ind = n-1 then ind+2 will cause error
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        
        if(buy){
            int take = -arr[ind] + f(ind+1,0,n,arr,dp);
            int notTake = 0 + f(ind+1,1,n,arr,dp);
            profit = max(take,notTake);
        }
        else{
            int sell = arr[ind] + f(ind+2,1,n,arr,dp);
            int notsell = 0 + f(ind+1,0,n,arr,dp);
            profit = max(sell,notsell);
        }
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return f(0,1,n,prices,dp);
        
    }
};