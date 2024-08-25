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
    void helperPostorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
        {
            return;
        }    
        else
        {
            // travelling left subtree
            helperPostorder(root -> left, nodes);
            // travelling right subtree
            helperPostorder(root -> right, nodes);

            nodes.push_back(root -> val);
        }
    }


    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> nodes;

        helperPostorder(root, nodes);

        return nodes;
    }
};