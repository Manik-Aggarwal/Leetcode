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



// class Solution {
// public:
//     bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
//         if(target==0) return true;
//         if(ind == 0) return arr[0] == target;
        
//         if(dp[ind][target]!=-1) return dp[ind][target];

//         bool notTaken = f(ind-1,target,arr,dp);

//         bool taken = false;
//         if(arr[ind]<=target) taken = f(ind-1,target-arr[ind],arr,dp);

//         return dp[ind][target] = notTaken||taken;
//     }
    
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int s = 0;
        
//         for(int i=0; i<n; i++) s += nums[i];
        
//         int k = s/2;
//         vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
//         if(s%2 == 1) return false;
//         else return f(n-1,k,nums,dp);
//     }
// };


class Solution{
public:
    bool canPartition(vector<int> &nums){
        int totSum=0;
        int n = nums.size();
        for(int i=0; i<n;i++) totSum += nums[i];
        if (totSum%2==1) return false;
    
        else{
            int k = totSum/2;
            vector<vector<bool>> dp(n,vector<bool>(k+1,false));

            // the base conditions
            for(int i=0; i<n; i++) dp[i][0] = true;
            if(nums[0]<=k) dp[0][nums[0]] = true;

            for(int ind = 1; ind<n; ind++){
                for(int target= 1; target<=k; target++){
                    bool notTaken = dp[ind-1][target];

                    bool taken = false;
                    if(nums[ind]<=target) taken = dp[ind-1][target-nums[ind]];

                    dp[ind][target]= notTaken||taken;
                }
            }
            return dp[n-1][k];
        } 
    }
};