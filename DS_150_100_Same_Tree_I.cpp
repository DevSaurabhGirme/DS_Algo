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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        if(p == NULL || q == NULL)
        {
            return false;
        }

        if(p -> val != q -> val)
        {
            return false;
        }

        // Check if the left subtrees of p and q are identical
        bool leftSubtreesEqual = isSameTree(p->left, q->left);

        // Check if the right subtrees of p and q are identical
        bool rightSubtreesEqual = isSameTree(p->right, q->right);

        // Combine the results of both subtree comparisons
        bool treesAreEqual = leftSubtreesEqual && rightSubtreesEqual;

        return treesAreEqual;
        
        //return isSameTree(p -> left, q -> left) && isSameTree(q -> right, q -> right);
    }
};