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
class Solution {
public:
    bool checkValid(TreeNode* curr_node,long int l, long int r)
    {
        if(curr_node == NULL)
        {
            return true;
        }

        if(curr_node -> val <= l || curr_node -> val >= r)
        {
            return false;
        }

        // exploring left subtree
        // update right limit so that left subtree node will follow the 
        // "should be less than root(question given) and immediate root"
        bool result_l = checkValid(curr_node -> left, l, curr_node -> val);
        
        // update left limit so that right subtree node will follow the 
        // "should be greater than root(question given) and immediate root"
        bool result_r = checkValid(curr_node -> right, curr_node -> val, r);

        return result_l && result_r;
    
    }

    bool isValidBST(TreeNode* root) 
    {
        long int min_left = LONG_MIN;
        long int max_right = LONG_MAX;

        return checkValid(root, min_left, max_right);    
    }
};