//////////////////////////////Recursion/////////////////////////////////
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>> &grid){
//         if(i == 0 && j == 0) return grid[i][j];
//         if(i<0 || j<0) return 1e9;
        
//         int up = grid[i][j] + f(i-1,j,grid);
//         int left = grid[i][j] + f(i,j-1,grid);
        
//         return min(up,left);
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         return f(m-1,n-1,grid);
//     }
// };

/////////////////////////////memoization///////////////////////////////
class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector(n,-1));
        
        return f(m-1,n-1,grid,dp);
    }
};