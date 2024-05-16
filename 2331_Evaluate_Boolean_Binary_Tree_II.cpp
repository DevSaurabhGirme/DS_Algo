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

        if(root -> val == 0){
            return false;
        }
        if(root -> val == 1){
            return true;
        }

        // OR
        if(root -> val == 2){
            return evaluateTree(root -> left) || evaluateTree(root -> right);
        }
        // AND
        if(root -> val == 3){
            return evaluateTree(root -> left) && evaluateTree(root -> right);
        }
    
        return false;
    }
};