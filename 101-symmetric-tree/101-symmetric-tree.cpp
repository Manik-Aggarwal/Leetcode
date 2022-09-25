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
    bool solve(TreeNode* lt, TreeNode* rt){
        if(!lt || !rt) return lt == rt;
        if(lt->val != rt->val) return false;
        
        return solve(lt->left, rt->right) && solve(lt->right, rt->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || solve(root->left, root->right);
    }
};