class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //By kadane's algo
        int max = INT_MIN;
        int temp = 0;
        
        for(int i=0; i<nums.size(); i++){
            temp += nums[i];
            
            if(temp > max) max = temp;
            if(temp < 0) temp = 0;

        }
         return max;
    }
};