//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
   #define MOD 1000000007
class Solution{
    public:

   long long int dp[1005][1005];
   string S;
   long long int countPS(string str)
   {
      const int n = str.length();
      
      memset(dp, -1, sizeof(dp));
      
      S = str;
      
      long long int ans = solve(0, n-1);
      return ans<0?ans+MOD:ans;
   }
   
   private:
   long long int solve(int i, int j){
       if(i > j) return 0;
       
       if(dp[i][j] != -1) return dp[i][j]%MOD;
       
       if(i == j) return dp[i][j] = 1;
       
       if(S[i] == S[j]){
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD + 1)%MOD;
       }
       else{
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD - solve(i+1, j-1)%MOD)%MOD;
       }
   }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends