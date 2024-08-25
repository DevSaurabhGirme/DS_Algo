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

// T.C = O(n)   S.C = O(n)

class Solution {
public:
    vector<int> nodes;

    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return nodes;
        }    

        // travelling left subtree
        postorderTraversal(root -> left);
        // travelling right subtree
        postorderTraversal(root -> right);

        nodes.push_back(root -> val);

        return nodes;
    }
};