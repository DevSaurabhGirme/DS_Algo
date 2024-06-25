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

// T.C = O(n)   S.C = O(1) + Stacks

class Solution {
public:
    void GST(TreeNode* curr_node, int& Sum)
    {
        if(curr_node == NULL)
        {
            return;
        }

        // exploring right subtree first
        GST(curr_node -> right, Sum);
        // calculating sum
        Sum = Sum + curr_node -> val;
        // updating the node's value
        curr_node -> val = Sum;

        // exploring left subtree
        GST(curr_node -> left, Sum);
    }

    TreeNode* bstToGst(TreeNode* root) 
    {
        int Sum = 0;

        GST(root, Sum);    

        return root;
    }
};