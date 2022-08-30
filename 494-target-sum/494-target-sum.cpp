//similar as partition with given diff
class Solution {
public:
    int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notTaken = f(ind-1,target,arr,dp);

        int taken = 0;
        if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr,dp);

        return dp[ind][target] = (notTaken + taken);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(target<0 && abs(target)!= abs(nums[0])) return 0;
        }
        
        int sum=0;
        for(auto e: nums) sum+=e;
        
        if( (sum-target)<0 || (sum-target)%2) return 0;
        
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        
        return f(n-1, (sum-target)/2, nums, dp);
    }
};
