class Solution {
public:
    bool helper(int n,int m,string&s,string&p,vector<vector<int>>&dp){
        if(n<0 && m<0) return true;
        if(n<0 && m>=0) return false;
        if(m<0 && n>=0){
            for(int i=0;i<=n;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s[m]==p[n] || p[n]=='?') return dp[n][m]=helper(n-1,m-1,s,p,dp);
        if(p[n]=='*'){
            bool a=helper(n-1,m,s,p,dp);
            bool b=helper(n,m-1,s,p,dp);
            return dp[n][m]=a||b;
        }
        
        return dp[n][m]=false;
    }
    
    bool isMatch(string s, string p) 
    {
        int n=p.size();
        int m=s.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,p,dp);
    }
};