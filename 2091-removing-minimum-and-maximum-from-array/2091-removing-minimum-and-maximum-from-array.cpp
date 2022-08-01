class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto [n1,n2] = minmax_element(nums.begin(), nums.end());
        
        int minIndex = n1 - nums.begin();
        int maxIndex = n2 - nums.begin();
        
        int removefromLeft = max(minIndex,maxIndex) + 1;
        int removefromRight = nums.size() - min(minIndex,maxIndex);
        int removefromBothSide = min(minIndex,maxIndex) + 1 + nums.size() - max(minIndex,maxIndex);
        
        return min({removefromLeft,removefromRight,removefromBothSide});
    }
};