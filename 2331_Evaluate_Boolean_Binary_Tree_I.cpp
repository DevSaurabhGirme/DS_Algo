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

// T.C = O(n)   S.C = O(depth of tree) + auxilary spcae of stacks in recursion

class Solution {
public:
    bool evaluateTree(TreeNode* root) 
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            return root -> val;
        }

        // recursive calls until leaf node
        int left = evaluateTree(root -> left);
        int right = evaluateTree(root -> right);
        
        if(root -> val == 2)
        {
            // OR
            return left | right;
        }
        // AND
        return left & right;
        
    }
};