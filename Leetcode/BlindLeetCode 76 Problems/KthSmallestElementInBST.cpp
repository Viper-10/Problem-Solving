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
    int kthSmallest(TreeNode* root, int& k) {
        if(k == 0){
            return root->val; 
        }
        int ans = -1;         
        
        if(root->left) ans = kthSmallest(root->left, k); 
        k -= 1; 
        
        if(k == 0) ans = root->val; 
        
        if(ans == -1 && root->right) ans = kthSmallest(root->right, k); 
        
        return ans; 
    }
};