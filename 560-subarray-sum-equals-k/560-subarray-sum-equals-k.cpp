class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        
        for(auto y:nums){
            sum += y;
            int x = sum - k;
            
            std::cout<<x<<",";
            if(mp.find(x) != mp.end()) ans += mp[x];
            
            mp[sum]++;
        }
        
        std::cout<<endl;
        for(auto in:mp) std::cout<<in.first<<",";
        
        return ans;
    }
};