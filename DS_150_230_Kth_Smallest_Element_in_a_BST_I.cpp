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

// S.C = O(n)   T.C = O(nlogn)

class Solution {
public:
    void preTraverse(TreeNode* curr_node, vector<int>& nodeVals)
    {
        if(curr_node == NULL)
        {
            return;
        }

        nodeVals.push_back(curr_node -> val);
        preTraverse(curr_node -> left, nodeVals);
        preTraverse(curr_node -> right, nodeVals);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        // to store values of each node
        vector<int> nodeVals;

        preTraverse(root, nodeVals);

        sort(nodeVals.begin(), nodeVals.end());

        return nodeVals[k-1]; 
    }
};