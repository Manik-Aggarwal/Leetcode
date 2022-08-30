// class Solution {
// public:
//     int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
//         if(ind == 0){
//             if(target==0 && arr[0]==0) return 2;
//             if(target==0 || target == arr[0]) return 1;
//             return 0;
//         }

//         if(dp[ind][target]!=-1) return dp[ind][target];

//         int notTaken = f(ind-1,target,arr,dp);

//         int taken = 0;
//         if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr,dp);

//         return dp[ind][target] = (notTaken + taken);
//     }

//     int countPartitions(int n, int d, vector<int> &arr) {    
//         int totalsum=0;
//         vector<vector<int>> dp(n,vector<int>(d+1,-1));
        
//         for(auto it : arr)totalsum +=it;
//         if(totalsum-d < 0 || (totalsum-d) % 2 ) return 0;

//         return f(n-1, (totalsum-d) / 2, arr, dp);
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         return countPartitions(n, target, nums);
//     }
// };

//similar as partition with given diff
class Solution {
public:
    int solve(vector<int>& nums, int sum, int i,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(nums[0]==0 && sum==0) return dp[i][sum]=2;
            if(sum==0 || sum==nums[0]) return dp[i][sum]=1;
            dp[i][sum]=0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notake= solve(nums,sum,i-1,dp);
        int take=0;
        if(sum>=nums[i])
        {
            take= solve(nums, sum-nums[i],i-1,dp);
        }
        return dp[i][sum]= take+notake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
        if(n==1)
        {
            if(target<0 && abs(target)!= abs(nums[0])) return 0;
        }
         int sum=0;
        for(auto &e: nums)
        {
            sum+=e;
        }
        if( (sum-target)<0 || (sum-target)%2) return 0;
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        return solve(nums,(sum-target)/2,n-1,dp);
    }
};
