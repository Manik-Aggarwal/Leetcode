class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return false;
        
        else{
            vector<pair<int,int>> v;
            
            for(int i=0; i<n; i++) v.push_back( make_pair(nums[i], i) );
            
            // before sorting
            // nums[i]   1 2 3 1
            // index     0 1 2 3 
            sort(v.begin(),v.end());
            // after sorting
            // nums[i]   1 1 2 3
            // index     0 3 1 2
            
            for(int i=1; i<n; i++){
                if(v[i].first == v[i-1].first && abs(v[i].second - v[i-1].second) <=k)
                    return true;
            }
        }
        return false;
    }
};