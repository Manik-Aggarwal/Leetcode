class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        int ans;
        
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        
        for(auto x : m) if(x.second > 1) ans = x.first;
        
        return ans;
    }
};