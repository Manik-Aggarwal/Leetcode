//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int cnt0 = 0, cnt1 = 0;
        int count = 0;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '0') cnt0++;
            else cnt1++;
            
            if(cnt0 == cnt1) count++;
        }
        
        if (cnt0!=cnt1) return -1;
        else return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends