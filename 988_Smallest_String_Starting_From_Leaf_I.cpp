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

// T.C = O(n)+O(length of curr_String)  S.C = O(n)

class Solution {
public:

    string sString = "";

    void DFS(TreeNode* curr_node, string curr_String)
    {
        if(curr_node == NULL)
        {
            return;
        }

        // appending character to the left of resultant string
        curr_String = char(curr_node -> val + 'a') + curr_String;

        // leaf node found
        if(curr_node -> left == NULL && curr_node -> right == NULL)
        {
            // if new smaller string found at this leaf node then
            if(sString == "" || sString > curr_String)
            {
                // assign it to resultant string
                sString = curr_String;
            }

            return;
        }

        // traversing in depth
        DFS(curr_node -> left, curr_String);
        DFS(curr_node -> right, curr_String);
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        // primary call with root and curr_String as empty
        DFS(root, "");

        return sString;
        
    }
};