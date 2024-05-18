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

// T/C = O(n)   S.C = O(depth of tree)

class Solution {
public:
    int Recur(TreeNode* root,int &moves)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left_subTree = Recur(root -> left, moves);
        int right_subTree = Recur(root -> right, moves);
    
        // update moves with absolute value of excess coins in left and right child
        moves = moves + abs(left_subTree) + abs(right_subTree);
    
        // Return the net balance of coins at current node
        return (left_subTree + right_subTree + root -> val) - 1;
    
    }

    int distributeCoins(TreeNode* root) 
    {
        int moves = 0;

        Recur(root, moves);

        return moves;
        
    }
};