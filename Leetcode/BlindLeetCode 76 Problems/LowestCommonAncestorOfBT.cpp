/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        bool pFound = false, qFound = false;

        if (root->val == p->val)
        {
            pFound = true;
        }

        else if (root->val == q->val)
        {
            qFound = true;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left)
        {
            if (left->val != p->val && left->val != q->val)
            {
                return left;
            }

            else
            {
                if (left->val == p->val)
                    pFound = true;
                else
                    qFound = true;
            }
        }

        if (right)
        {
            if (right && right->val != p->val && right->val != q->val)
            {
                return right;
            }
            else
            {
                if (right->val == p->val)
                {
                    pFound = true;
                }
                else
                {
                    qFound = true;
                }
            }
        }

        if (pFound && qFound)
        {
            return root;
        }

        if (pFound)
        {
            return p;
        }

        else if (qFound)
        {
            return q;
        }

        return NULL;
    }
};