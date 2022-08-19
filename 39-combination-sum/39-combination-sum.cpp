class Solution {
public:
    void solve(int i, vector<int> &temp, vector<vector<int>> &ans, int target, vector<int> &arr){
        if(i == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        //include
        if(arr[i] <= target){
            temp.push_back(arr[i]);
            solve(i, temp, ans, target-arr[i], arr);
            temp.pop_back();
        }
        
        //exclude
        solve(i+1, temp, ans, target, arr);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        
        solve(i, temp, ans, target, candidates);
        
        return ans;
    }
};