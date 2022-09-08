// class Solution {
// public:
//     int f(int i, vector<int> &arr, int k, vector<int> &dp){
//         int n = arr.size();
//         if(i == n) return 0;
//         if(dp[i] != -1) return dp[i];
//         int maxi = INT_MIN;
//         int maxAns = INT_MIN;
//         int len = 0;
        
//         for(int j=i; j<min(i+k,n); j++){
//             len++;
//             maxi = max(maxi,arr[j]);
//             int sum = len*maxi + f(j+1,arr,k,dp);
//             maxAns = max(maxAns,sum);
//         }
//         return dp[i] = maxAns;
//     }
    
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {    
//         vector<int> dp(arr.size(),-1);
//         return f(0,arr,k, dp);
//     }
// };

class Solution {
public:    
    int maxSumAfterPartitioning(vector<int>& arr, int k) { 
        int n = arr.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1; i>= 0; i--){
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            int len = 0;

            for(int j=i; j<min(i+k,n); j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[i] = maxAns;
        }
        
        return dp[0];
    }
};