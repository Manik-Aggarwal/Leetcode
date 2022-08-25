///////////////////////////Recursion/////////////////////////////
// class Solution {
// public:
//     int f(int i, int j, vector<vector<int>>& triangle){
//         if(i == triangle.size()-1) return triangle[i][j];
        
//         int down = triangle[i][j] + f(i+1,j,triangle);
//         int downright = triangle[i][j] + f(i+1,j+1,triangle);
        
//         return min(down,downright);
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         return f(0,0,triangle);
//     }
// };

///////////////////////memoization///////////////////////
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == triangle.size()-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1,j,triangle,dp);
        int downright = triangle[i][j] + f(i+1,j+1,triangle,dp);
        
        return dp[i][j] = min(down,downright);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        vector<vector<int>> dp(m,vector<int>(triangle[m-1].size(),-1));
        
        return f(0,0,triangle,dp);
    }
};