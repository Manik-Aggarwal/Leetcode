class Solution {
public:
    //by using hashmap
//     int majorityElement(vector<int>& nums) {
//         unordered_map <int,int> m;
//         int ans;
        
//         for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        
//         for(int i=0; i<nums.size(); i++){
//             if(m[nums[i]] > nums.size()/2) ans = nums[i];
//         }
//         return ans;
//     }
    
    //by Moore's voting algo
     int majorityElement(vector<int>& nums) {
        int count = 0;
         int elem = 0;
         
         for(int num : nums){
             if(count==0) elem = num;
             
             if(num == elem) count++;
             
             else count--;
         }
         
         return elem;
    }
};