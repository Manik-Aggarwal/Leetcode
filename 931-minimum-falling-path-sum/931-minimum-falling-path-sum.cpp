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
// class Solution {
// public:
//     int f(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
//         if(j<0 || j>=n) return 1e9;
//         if(i==0) return matrix[0][j];
        
//         if(dp[i][j] != -1) return dp[i][j];

//         int up = matrix[i][j] + f(i-1,j,n,matrix,dp);
//         int leftDiagonal = matrix[i][j] + f(i-1,j-1,n,matrix,dp);
//         int rightDiagonal = matrix[i][j] + f(i-1,j+1,n,matrix,dp);

//         return dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         int mini = INT_MAX;
//         for(int j=0; j<n; j++){
//             int ans = f(m-1,j,n,matrix,dp);
//             mini = min(mini,ans);
//         }
        
//         return mini;
//     }
// };

//////////////////////////////////Tabulation////////////////////////////
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,0));
        
//         for(int j=0; j<n; j++) dp[0][j] = matrix[0][j];
        
//         for(int i=1; i<m; i++){
//             for(int j=0; j<n; j++){
//                 int up = matrix[i][j] + dp[i-1][j];
                
//                 int leftDiagonal = matrix[i][j];
//                 if(j-1 >= 0) leftDiagonal += dp[i-1][j-1];
//                 else leftDiagonal += 1e9;
                
//                 int rightDiagonal = matrix[i][j];
//                 if(j+1 < n) rightDiagonal += dp[i-1][j+1];
//                 else rightDiagonal += 1e9;
                
//                 dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
//             }
//         }
        
//         int mini = INT_MAX;
//         for(int j=0; j<n; j++) mini = min(mini,dp[n-1][j]);
//         return mini;
//     }
// };

//////////////////////////////Space Optimisation////////////////////////////
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0), curr(m,0);
        
        for(int j=0; j<n; j++) prev[j] = matrix[0][j]; //here prev make sure
        
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];
                
                int leftDiagonal = matrix[i][j];
                if(j-1 >= 0) leftDiagonal += prev[j-1];
                else leftDiagonal += 1e9;
                
                int rightDiagonal = matrix[i][j];
                if(j+1 < n) rightDiagonal += prev[j+1];
                else rightDiagonal += 1e9;
                
                curr[j] = min(up,min(leftDiagonal,rightDiagonal));
            }
            prev = curr;
        }
        
        int mini = INT_MAX;
        for(int j=0; j<n; j++) mini = min(mini,prev[j]);
        return mini;
    }
};