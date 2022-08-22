class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        string ans = "";
        int fact = 1;
        
        for(int i=1; i<n; i++){ // calculate fact of n-1
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n); //push nth number in vector
        k = k-1;
        
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact); //deletes the number at pos k/fact
            
            if(nums.size() == 0) break;
            
            k = k%fact;
            fact = fact/nums.size();
        }
        
        return ans;
    }
};