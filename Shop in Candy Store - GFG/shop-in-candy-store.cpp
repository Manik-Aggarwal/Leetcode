//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        vector<int> ans;
        
        int mini = 0;
        int buy = 0;
        int free = N-1;
        
        while(buy <= free){
            mini = mini + candies[buy];
            buy++;
            free = free-K;
        }
        
        int maxi = 0;
        int free2 = 0;
        int buy2 = N-1;
        
        while(buy2 >= free2){
            maxi = maxi + candies[buy2];
            buy2--;
            free2 = free2+K;
        }
        
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends