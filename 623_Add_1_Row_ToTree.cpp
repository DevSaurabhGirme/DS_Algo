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
    // Function to add the new node with value = 'val'
    TreeNode* addRow(TreeNode* curr_node, int val, int depth, int curr_depth)
    {
        if(curr_node == NULL)
        {
            return NULL;
        }

        // position to add the new value
        if(curr_depth == depth-1)
        {
            TreeNode* left_temp = curr_node -> left;
            TreeNode* right_temp = curr_node -> right;

            // creation of new node
            curr_node -> left = new TreeNode(val);
            curr_node -> right = new TreeNode(val);

            curr_node -> left -> left = left_temp;
            curr_node -> right -> right = right_temp;
        
            return curr_node;
        }

        // store the updated tree structure after adding the desired node
        // for every curr_node acting as a root/parent for its child nodes
        curr_node -> left = addRow(curr_node -> left, val, depth, curr_depth+1);    // Recursive call to travel to desired depth
        curr_node -> right = addRow(curr_node -> right, val, depth, curr_depth+1);  // Recursive call to travel to desired depth

        // return changes made during the recursive tree traversal 
        // these changes are properly reflected and propagated back
        // through the tree structure in the form of curr_node.

        // during recursive call unwinding the returned curr_node
        // effectively represents the updated subtree structure.

        return curr_node;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
            // creating new Tree structure itself
            if(depth == 1)
            {
                TreeNode* newRoot = new TreeNode(val);
                newRoot -> left = root;

                return newRoot;
            }

            int curr_depth = 1;

            // primary call
            return addRow(root, val, depth, curr_depth);
    }
};