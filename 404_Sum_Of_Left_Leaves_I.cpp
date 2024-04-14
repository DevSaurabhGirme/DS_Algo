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

// T.C = O(n) S.C = O(1) + Auxillary O(depth of tree)

class Solution {
public:

    int Solve(TreeNode* curr_node,TreeNode* parent)
    {
        if(curr_node == NULL)
        {
            return 0;
        }

        if(curr_node -> left == NULL && curr_node -> right == NULL)
        {
            // leaf found
            if(parent != NULL && parent -> left == curr_node)
            {
                return curr_node -> val;
            }
        }

        //                      root         parent
        int left = Solve(curr_node -> left, curr_node);   // Recursive call
        int right = Solve(curr_node -> right, curr_node); // Recursive call
    
        return left+right;
    }

    int sumOfLeftLeaves(TreeNode* root) 
    {
        return Solve(root, NULL);    
    }
};