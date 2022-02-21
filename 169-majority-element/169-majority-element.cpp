class Solution {
public:
    //by using hashmap
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> m;
        int ans;
        
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        
        for(int i=0; i<nums.size(); i++){
            if(m[nums[i]] > nums.size()/2) ans = nums[i];
        }
        return ans;
    }
};