class Solution {
public:
    int f(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
    
        for(int i=1; i<n; i++){
            int include = nums[i];
            if(i>1) include += prev2;

            int exclude = 0 + prev;

            int curr = max(include,exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> excludingfirstnum;
        vector<int> excludinglastnum;
        
        if(n == 1) return nums[0];
        
        for(int i=0; i<n; i++){
            if(i != 0) excludingfirstnum.push_back(nums[i]);
            if(i != n-1) excludinglastnum.push_back(nums[i]);
        }
        
        return max(f(excludingfirstnum), f(excludinglastnum));
    }
};