class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int index = s + (e-s)/2;
        
        while(s<=e){
            if(nums[index] == target) return index;
            else if(nums[index] > target) e = index - 1;
            else s = index + 1;
            
            index = s + (e-s)/2;
        }
        return s;
    }
};