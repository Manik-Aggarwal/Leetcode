class Solution {
public:
    int f(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=n || j2>=n) return -1e8;
        
        if(i == m-1){ // if both are at last row
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                
                value += f(i+1, j1 + dj1, j2 + dj2, m, n, grid, dp);
                
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startRow = 0;
        int robo1col = 0;
        int robo2col = n-1;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return f(startRow,robo1col,robo2col,m,n,grid,dp);
    }
};