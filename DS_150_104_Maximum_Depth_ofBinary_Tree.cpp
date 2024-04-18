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

// T.C = O(n)   S.C = O(d) d = depth of tree

class Solution {
public:

    int DFS(TreeNode* curr_node, int curr_depth)
    {
        if(curr_node == NULL)
        {
            return 0;
        }

        // leaf node detected
        if(curr_node -> left == NULL && curr_node -> right == NULL)
        {
            return curr_depth;
        }

        // The below depths with be considered as initalization only if the curr_node has left or right child 
        
        // depth of left side of tree
        int left_depth = 1;
        // depth of right side of tree
        int right_depth = 1;

        // initialized to value 1 because we have already traveled one depth unit to reach the child

        // travel the depth
        if(curr_node -> left != NULL || curr_node -> right != NULL)
        {
            // hence calculating left and right child depth separately
            if(curr_node -> left != NULL)
            {
                left_depth = DFS(curr_node -> left, left_depth);
            }
            if(curr_node -> right != NULL)
            {
                right_depth = DFS(curr_node -> right, right_depth);
            }

            curr_depth = max(left_depth, right_depth) + 1;    
        }
        return curr_depth;
    }

    int maxDepth(TreeNode* root) 
    {
        int depth = 1;

        depth = DFS(root, depth);

        return depth;   
    }
};