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
    void findSmallest(TreeNode* curr_node, int& smallestInt, int k, int& count)
    {
        if(curr_node == NULL)
        {
            return;
        }

        // explore left subtree
        findSmallest(curr_node -> left, smallestInt, k, count);
        
        count++;
        if(count == k)
        {
            smallestInt = curr_node -> val;
        }

        // explore right subtree
        findSmallest(curr_node -> right, smallestInt, k, count);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        int smallestInt = 0;
        // number of smallest element
        int count = 0;

        findSmallest(root, smallestInt, k, count);

        return smallestInt; 
    }
};