typedef pair<int,int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        
        priority_queue<pp, vector<pp>, greater<pp>> q;
        
        for(auto it = m.begin(); it != m.end(); it++){
            q.push({it->second,it->first});
            
            if(q.size() > k) q.pop();
        }
        
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};