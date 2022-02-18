class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) { 
        int n = nums.size();
        unordered_set <int> temp;
        vector <int> result;
        
        for(int i : nums) temp.insert(i);
                
        for(int i = 1 ; i <= n ; i++)
            if(temp.find(i) == temp.end())
                result.push_back(i);
        
        return result;
    }
};