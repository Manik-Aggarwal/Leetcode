class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m1, m2;
        
        // inserting arr value in m1 using hash
        for(auto x : arr) m1[x]++;
        
        // inserting second values of m1 in m2 (means occurrences in m2)
        for(auto y : m1) m2[y.second]++;
        
        // checking if m2 values are unique or not
        for(auto check : m2){
            if(check.second > 1) return false;
        }
        
        return true;
    }
};