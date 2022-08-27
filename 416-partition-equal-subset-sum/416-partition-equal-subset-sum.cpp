// class Solution {
// public:
//     bool f(int ind, int target, vector<int>& arr){
//         if(target==0) return true;
//         if(ind == 0) return arr[0] == target;

//         bool notTaken = f(ind-1,target,arr);

//         bool taken = false;
//         if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr);

//         return notTaken||taken;
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int s = 0;
//         for(int i=0; i<n; i++) s += nums[i];
        
//         if(s%2 == 1) return false;
//         else return f(n-1,s/2,nums);
//     }
// };



class Solution {
public:
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind == 0) return arr[0] == target;
        
        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTaken = f(ind-1,target,arr,dp);

        bool taken = false;
        if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr,dp);

        return dp[ind][target] = notTaken||taken;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        
        for(int i=0; i<n; i++) s += nums[i];
        
        int k = s/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        if(s%2 == 1) return false;
        else return f(n-1,k,nums,dp);
    }
};