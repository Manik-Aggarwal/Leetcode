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
     int ans,num=0 ;
    
    void find(TreeNode* root, int k){
        if(!root) return ;
        
        find(root->left,k);
        
        num++;
        if(num==k) ans = root->val;
        find(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return ans;
        
    }
};