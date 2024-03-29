//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            map<int, int> mp;
            vector<int> vect;
            
            for(int i=0; i<n1; i++) mp[A[i]] = 1;
            
            for(int i = 0; i < n2; i++){
                if(mp[B[i]]) mp[B[i]] = 2;
            }
            
            for(int i = 0;i < n3; i++){
                if(mp[C[i]] == 2) mp[C[i]] = 3;
            }
            
            for(auto itr = mp.begin(); itr != mp.end(); itr++){
                if(itr->second == 3) vect.push_back(itr->first);
            }
            
            if(vect.size() == 0) return {-1};
            else return vect;
        }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends