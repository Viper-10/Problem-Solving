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
    bool checkIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true; 
        
        if(root == NULL || subRoot == NULL || root->val != subRoot->val) return false; 
        
        return checkIdentical(root->left, subRoot->left) && checkIdentical(root->right, subRoot->right);      
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;     
        }
        
        if(root->val == subRoot->val && checkIdentical(root, subRoot)){
            return true; 
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);                
    }
};