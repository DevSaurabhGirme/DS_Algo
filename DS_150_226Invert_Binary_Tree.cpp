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
    void Invert(TreeNode* curr_node)
    {
        if(curr_node == NULL || (curr_node -> left == NULL && curr_node -> right == NULL))
        {
            return;
        }

        Invert(curr_node -> left);
        Invert(curr_node -> right);

        // swapping nodes exactly like numbers
        TreeNode* temp = curr_node -> left;
        curr_node -> left = curr_node -> right;
        curr_node -> right = temp;

        return;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        Invert(root);

        return root;    
    }
};