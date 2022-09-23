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

/////////////////////////Recursion///////////////////////////////
// class Solution {
// public:
//     void solve(TreeNode* node, vector<int> &ans){
//         if(!node) return;
        
//         solve(node->left, ans);
//         solve(node->right, ans);
//         ans.push_back(node->val);
//     }
    
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         solve(root,ans);
        
//         return ans;
//     }
// };

/////////////////////////Using 2 stack////////////////////////////
// class Solution {
// public:    
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         stack<TreeNode*> st1, st2;
        
//         st1.push(root);
        
//         while(!st1.empty()){
//             TreeNode* node = st1.top();
//             st1.pop();
//             st2.push(node);
            
            
//             if(node->left) st1.push(node->left);
//             if(node->right) st1.push(node->right);
//         }
        
//         while(!st2.empty()){
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }
        
//         return ans;
//     }
// };

////////////////////Using 1 stack/////////////////////////////////////
class Solution {
public:    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* node = st.top()->right;
                if(!node){
                    node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    while (!st.empty() && node == st.top()->right) {
                      node = st.top();
                      st.pop();
                      ans.push_back(node->val);
                    }
                }
                else root = node;
            }
        }
        
        return ans;
    }
};