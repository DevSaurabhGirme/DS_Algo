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

// S.C = O(n)   T.C = O(n)

class Solution {
public:
    void inTraverse(TreeNode* curr_node, vector<int>& nodeVals)
    {
        if(curr_node == NULL)
        {
            return;
        }

        // explore left subtree
        inTraverse(curr_node -> left, nodeVals);
        // insert node value
        nodeVals.push_back(curr_node -> val);
        // explore right subtree
        inTraverse(curr_node -> right, nodeVals);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        // to store values of each node
        vector<int> nodeVals;

        inTraverse(root, nodeVals);

        return nodeVals[k-1]; 
    }
};