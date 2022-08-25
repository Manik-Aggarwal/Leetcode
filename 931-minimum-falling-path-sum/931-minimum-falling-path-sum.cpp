///////////////////////////Recursion///////////////////////////
// class Solution {
// public:
//     int f(int i, int j, int n, vector<vector<int>> &matrix){
//         if(j<0 || j>=n) return 1e9;
//         if(i==0) return matrix[0][j];

//         int up = matrix[i][j] + f(i-1,j,n,matrix);
//         int leftDiagonal = matrix[i][j] + f(i-1,j-1,n,matrix);
//         int rightDiagonal = matrix[i][j] + f(i-1,j+1,n,matrix);

//         return min(up,min(leftDiagonal,rightDiagonal));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int mini = INT_MAX;
//         for(int j=0; j<n; j++){
//             int ans = f(m-1,j,n,matrix);
//             mini = min(mini,ans);
//         }
        
//         return mini;
//     }
// };

////////////////////////////Memoization///////////////////////////////
class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j<0 || j>=n) return 1e9;
        if(i==0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + f(i-1,j,n,matrix,dp);
        int leftDiagonal = matrix[i][j] + f(i-1,j-1,n,matrix,dp);
        int rightDiagonal = matrix[i][j] + f(i-1,j+1,n,matrix,dp);

        return dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            int ans = f(m-1,j,n,matrix,dp);
            mini = min(mini,ans);
        }
        
        return mini;
    }
};