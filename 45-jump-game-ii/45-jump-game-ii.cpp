class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, temp = 0, curr = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            if(i + nums[i] > temp) temp = i + nums[i];
            
            if(i == curr){
                curr = temp;
                jump++;
            }
        }
        return jump;
    }
};