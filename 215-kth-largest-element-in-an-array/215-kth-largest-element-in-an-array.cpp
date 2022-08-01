class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> q;
        
        for(int n : nums) q.push(n);
        
        for(int i=0; i<k; i++){
            if(i == k-1) return q.top();
            else q.pop();
        }
        return -1;
    }
};