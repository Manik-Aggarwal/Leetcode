class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), count(n,1);
        int maxi = 1;
        
        for(int ind = 0; ind<n; ind++){
            for(int prevInd = 0; prevInd<ind; prevInd++){
                if(nums[ind] > nums[prevInd] && 1+dp[prevInd]>dp[ind]){
                    dp[ind] = max(dp[ind], 1+dp[prevInd]);
                    count[ind] = count[prevInd];
                }
                else if(nums[ind] > nums[prevInd] && 1+dp[prevInd]==dp[ind]){
                    count[ind]  += count[prevInd];
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) ans += count[i];
        }
        
        return ans;
    }
};