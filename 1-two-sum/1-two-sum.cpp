class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end()){
                ans.push_back(m[target-nums[i]]);//pushing index syntax
                ans.push_back(i);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
        
        
        // vector <int> ans;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};