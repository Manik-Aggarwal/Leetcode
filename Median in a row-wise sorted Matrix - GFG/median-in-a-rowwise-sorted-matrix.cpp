//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int min = INT_MAX;
        int max = INT_MIN;
        
        for(int i=0; i<R; i++){
            if(matrix[i][0] < min) min = matrix[i][0];
            
            if(matrix[i][C-1] > max) max = matrix[i][C-1];
        }
        
        int ans = (R*C+1) / 2;
        
        while(min < max){
            int mid = min + (max-min)/2;
            int count = 0;
        
            for(int i=0; i<R; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].begin() + C, mid) - matrix[i].begin();

            }
            
            if(count < ans) min = mid + 1;
            else max = mid;
        }
        
        return min;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends