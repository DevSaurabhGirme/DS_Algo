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

// T.C = O(n)   S.C = O(depth of tree)

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(root == NULL)
        {
            return NULL;
        }

        // solving for left and right subtrees
        root -> left = removeLeafNodes(root -> left, target);
        root -> right = removeLeafNodes(root -> right, target);
    
        if(root -> left == NULL && root -> right == NULL && root -> val == target)
        {
            // delete root; // causes runtime error
            return NULL;
        }

        return root;
    
    }
};