/////////////////Reursion///////////////////////////////////
// class Solution {
// public:
//     int f(int index, vector<int> &nums){
//         if(index == 0) return nums[index];
//         if(index < 0) return 0;

//         int include = nums[index] + f(index-2, nums);
//         int exclude = 0 + f(index-1, nums);

//         return max(include,exclude);
//     }
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return f(n-1, nums);
//     }
// };

/////////////////Memoization//////////////////////////////////
// class Solution {
// public:
//     int f(int index, vector<int> &nums, vector<int> &dp){
//         if(index == 0) return nums[index];
//         if(index < 0) return 0;

//         if(dp[index] != -1) return dp[index];

//         int include = nums[index] + f(index-2, nums, dp);
//         int exclude = 0 + f(index-1, nums, dp);

//         return dp[index] = max(include,exclude);
//     }   
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return f(n-1, nums, dp);
//     }
// };

///////////////////////Tabulation////////////////////////////////
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,0);
//         dp[0] = nums[0];
    
//         for(int i=1; i<n; i++){
//             int include = nums[i];
//             if(i>1) include += dp[i-2];

//             int exclude = 0 + dp[i-1];

//             dp[i] = max(include,exclude);
//         }
//         return dp[n-1];
//     }
// };

//////////////////////////Space optimised withO(1)//////////////////
  class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
    
        for(int i=1; i<n; i++){
            int include = nums[i];
            if(i>1) include += prev2;

            int exclude = 0 + prev;

            int curr = max(include,exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
 
