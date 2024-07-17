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
    // finding the LowestCommonAncestoral node
    TreeNode* LCA(TreeNode* root, int src, int dest)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(root -> val == src || root -> val == dest)
        {
            return root;
        }

        // DFS Recursion
        TreeNode* left = LCA(root -> left, src, dest);
        TreeNode* right = LCA(root -> right, src, dest);

        if(left && right)
        {
            return root;
        }

        return left ? left : right;
    }

    // finding path from source_node to LCA_node and LCA_node to destination
    bool findPath(TreeNode* LCA_node, int target, string& path)
    {
        if(LCA_node == NULL)
        {
            return false;
        }

        if(LCA_node -> val == target)
        {
            return true;
        }

        // exploring left
        path.push_back('L');
        if(findPath(LCA_node -> left, target, path) == true)
        {
            return true;
        }

        // backtracking
        path.pop_back();

        // exploring right
        path.push_back('R');
        if(findPath(LCA_node -> right, target, path) == true)
        {
            return true;
        }
        
        // backtracking
        path.pop_back();

        return false;

    }


    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* LCA_node = LCA(root, startValue, destValue);   
    
        string LCA_to_src = "";
        string LCA_to_dest = "";

        findPath(LCA_node, startValue, LCA_to_src);
        findPath(LCA_node, destValue, LCA_to_dest);

        string result = "";

        for(int i = 0; i < LCA_to_src.length(); i++)
        {
            result.push_back('U');
        }

        result += LCA_to_dest;

        return result;
    }
};