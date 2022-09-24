/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &maxi){
        if(!root) return 0;
        
        int lp = max(0,solve(root->left, maxi));//to avoid -ve ans in summing
        int rp = max(0,solve(root->right, maxi));
        
        maxi = max(maxi, lp+rp+root->val);
        
        return root->val + max(lp,rp);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        
        solve(root, maxi);
        return maxi;
    }
};