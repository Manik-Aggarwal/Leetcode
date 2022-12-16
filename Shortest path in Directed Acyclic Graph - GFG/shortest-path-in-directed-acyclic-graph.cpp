//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topsort(int node, unordered_map<int,bool> &visited, stack<int> &s, unordered_map<int,list<pair<int,int>>> &adj){
        visited[node] = true;
    
        for(auto x : adj[node]){
            if(!visited[x.first]) topsort(x.first,visited,s,adj);
        }
        s.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            pair<int,int> p = make_pair(v,weight);
            
            adj[u].push_back(p);
        }
        
        //topological sort
        unordered_map<int,bool> visited;
        stack<int> s;
        for(int i=0; i<N; i++){
            if(!visited[i]) topsort(i,visited,s,adj);
        }
        
        //main part
         vector<int>dist(N,INT_MAX);
        dist[0] = 0;
        bool flag=true;
        
        while(!s.empty()){
            int top=s.top();
            s.pop();

            if(top!=0 && flag) continue;
            if(top==0) flag=false;

            for(auto i:adj[top]){
                int wt = i.second;
                int v = i.first;
                
                if(dist[top]+wt < dist[v]) dist[v]=dist[top]+wt;
            }
        }

        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }

        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends