///////////////////////////Recursion//////////////////////////
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>>& grid){
//         if(i<0 || j<0 || grid[i][j]==1) return 0;
//         if(i==0 && j==0) return 1;
        
//         int up=f(i-1,j,grid);
//         int left=f(i,j-1,grid);
        
//         return up+left;
//     }
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         return f(m-1,n-1, obstacleGrid);
//     }
// };

///////////////////////////Memoization//////////////////////////
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
//         if(i<0 || j<0 || grid[i][j]==1) return 0;
//         if(i==0 && j==0) return 1;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int up=f(i-1,j,grid, dp);
//         int left=f(i,j-1,grid, dp);
        
//         return dp[i][j] = up+left;
//     }
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         return f(m-1,n-1, obstacleGrid, dp);
//     }
// };

/////////////////////////////Tabulation///////////////////////////
class Solution{
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};