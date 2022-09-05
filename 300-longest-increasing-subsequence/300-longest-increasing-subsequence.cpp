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

/////////////////////////////Tabulation///////////////////////////////////////
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prevInd = ind-1; prevInd>=-1; prevInd--){
//                 int notTake = dp[ind+1][prevInd+1];
        
//                 int take = 0;
//                 if(prevInd == -1 || nums[ind]>nums[prevInd]) take = 1 + dp[ind+1][ind+1];
                
//                 dp[ind][prevInd+1] = max(take,notTake);
//             }
//         }
        
//         return dp[0][-1+1];
//     }
// };

/////////////////////////////Space Optimisation///////////////////////////////////////
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> next(n+1,0);
//         vector<int> curr(n+1,0);
        
//         for(int ind = n-1; ind >= 0; ind--){
//             for(int prevInd = ind-1; prevInd>=-1; prevInd--){
//                 int notTake = next[prevInd+1];
        
//                 int take = 0;
//                 if(prevInd == -1 || nums[ind]>nums[prevInd]) take = 1 + next[ind+1];
                
//                 curr[prevInd+1] = max(take,notTake);
//             }
//             next = curr;
//         }
        
//         return curr[-1+1];
//     }
// };

/////////////////////////////********************///////////////////////////////////////
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,1);
//         int maxi = 1;
        
//         for(int ind = 0; ind<n; ind++){
//             for(int prevInd = 0; prevInd<ind; prevInd++){
//                 if(nums[ind] > nums[prevInd]) dp[ind] = max(dp[ind], 1+dp[prevInd]);
//             }
            
//             maxi = max(maxi,dp[ind]);
//         }
        
//         return maxi;
//     }
// };


//////////////////printing lis///////////////////////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        for(int i=0; i<=n-1; i++){
            hash[i] = i;
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){

                if(nums[prev_index]<nums[i] && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }

        int ans = -1;
        int lastIndex =-1;
        
        //find max from dp array and index of max elem
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);    
        }

        reverse(temp.begin(),temp.end());
        
        for(int i=0; i<temp.size(); i++) std::cout<<temp[i]<<" ";
        std::cout<<endl;

        return ans;
    }
};




