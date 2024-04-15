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

// T.C = O(n) S.C = O(h) h = height of tree

class Solution {
public:

    int Solve(TreeNode* curr_node, int curr_sum)
    {
        if(curr_node == NULL)
        {
            return 0;
        }

        // append digits to form the number
        curr_sum = curr_sum * 10 + curr_node -> val;

        // leaf node found
        if(curr_node -> left == NULL && curr_node -> right == NULL)
        {
            return curr_sum;
        }

        //     continuing to find the sum from left and right
        return Solve(curr_node -> right, curr_sum) + Solve(curr_node -> left, curr_sum);
       
       
        /*
        int right_sum = Solve(curr_node -> right, curr_sum);
        int left_sum = Solve(curr_node -> left, curr_sum);
    
        int sum = right_sum + left_sum;

        return sum;
        */

    }

    int sumNumbers(TreeNode* root) 
    {
        // Solve(curr_node,curr_sum)
        // Priamry call
        
        return Solve(root, 0);     
    }
};