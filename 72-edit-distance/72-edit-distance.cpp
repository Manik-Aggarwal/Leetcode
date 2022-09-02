class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j<0) return i+1; //if str t exhausted
        if(i<0) return j+1; //if str s exhausted
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = 0 + f(i-1,j-1,s,t,dp);
        else{
            int insert = f(i,j-1,s,t,dp);
            int delet = f(i-1,j,s,t,dp);
            int replace = f(i-1,j-1,s,t,dp);
            
            return dp[i][j] = 1 + min(insert, min(delet,replace));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,word1,word2,dp);
    }
};