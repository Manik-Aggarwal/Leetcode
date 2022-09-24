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

///////////////////////////O(N^2)////////////////////////////////
// class Solution {
// public:
//     int maxDepth(TreeNode* root){
//         if(!root) return 0;
        
//         int lh = maxDepth(root->left);
//         int rh = maxDepth(root->right);
        
//         return 1 + max(lh,rh);
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         int lh = maxDepth(root->left);
//         int rh = maxDepth(root->right);
                
//         int lh1 = diameterOfBinaryTree(root->left);
//         int rh1 = diameterOfBinaryTree(root->right);
        
//         return max({lh+rh, lh1, rh1});
//     }
// };

////////////////////////////////O(N)//////////////////////////////////
class Solution {
public:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        
        diameter = max(diameter, lh + rh);
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        
        return diameter;
    }
};