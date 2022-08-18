class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,pair<int,int>>> q;
        
        for(int i=0; i<points.size(); i++){
            q.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0],points[i][1]}});
            
            if(q.size() > k) q.pop();
        }
        
        vector<vector<int>> ans;
        while(!q.empty()){
            ans.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        
        return ans;
    }
};