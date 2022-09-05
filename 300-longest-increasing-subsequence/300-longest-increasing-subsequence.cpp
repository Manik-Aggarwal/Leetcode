/////////////////////////////Recursion///////////////////////////////////////
// class Solution {
// public:
//     int f(int ind, int prevInd, vector<int> &nums, int n){
//         if(ind == n) return 0;
        
//         int notTake = f(ind+1,prevInd,nums,n);
        
//         int take = 0;
//         if(prevInd == -1 || nums[ind]>nums[prevInd]) take = 1 + f(ind+1,ind,nums,n);
        
//         return max(take,notTake);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         return f(0,-1,nums,nums.size());
//     }
// };

/////////////////////////////Memoization///////////////////////////////////////
// class Solution {
// public:
//     int f(int ind, int prevInd, vector<int> &nums, int n,vector<vector<int>> &dp){
//         if(ind == n) return 0;
//         if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        
//         int notTake = f(ind+1,prevInd,nums,n,dp);
        
//         int take = 0;
//         if(prevInd == -1 || nums[ind]>nums[prevInd]) take = 1 + f(ind+1,ind,nums,n,dp);
        
//         return dp[ind][prevInd+1] = max(take,notTake);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n+1,-1));
        
//         return f(0,-1,nums,n,dp);
//     }
// };

/////////////////////////////Memoization///////////////////////////////////////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int prevInd = ind-1; prevInd>=-1; prevInd--){
                int notTake = dp[ind+1][prevInd+1];
        
                int take = 0;
                if(prevInd == -1 || nums[ind]>nums[prevInd]) take = 1 + dp[ind+1][ind+1];
                
                dp[ind][prevInd+1] = max(take,notTake);
            }
        }
        
        return dp[0][-1+1];
    }
};