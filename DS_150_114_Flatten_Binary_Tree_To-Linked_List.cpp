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

// T.C = O(n)   S.C = O(h)

class Solution {
public:
    void getLinkedList(TreeNode* curr_node, TreeNode*& prev_node)
    {
        // Base case
        if(curr_node == NULL)
        {
            return;
        }

        if(prev_node != NULL)
        {
            prev_node -> left = NULL;
            // prev_node -> next = curr_node(LL)
            prev_node -> right = curr_node;
        }

        // storing right subtree root for future use in connecting the right 
        // subtree to the tail of the left subtree converted into Linkedlist
        TreeNode* right_root = curr_node -> right;
        prev_node = curr_node;

        // call to left subtree
        getLinkedList(curr_node -> left, prev_node);

        // call to right subtree nodes
        getLinkedList(right_root, prev_node);
    }

    void flatten(TreeNode* root) 
    {
        TreeNode* prev = NULL;
    
        getLinkedList(root, prev);
    }
};