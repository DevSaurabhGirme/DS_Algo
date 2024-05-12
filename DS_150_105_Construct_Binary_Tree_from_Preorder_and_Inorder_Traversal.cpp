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

    TreeNode* MissingChild(vector<int>& preorder, vector<int>& inorder, int start, int end, int& Idx)
    {
        if(start > end)
        {
            return NULL;
        }

        // 1st element of preorder is always the root
        // further it will change as we traverse
        int rootVal = preorder[Idx];
        
        // to traverse over inorder
        int i = start;
        for(; i <= end; i++)
        {
            // root found in inorder
            if(inorder[i] == rootVal)
            {
                break;
            }
        }

        Idx++;
        // builing tree with first root found
        TreeNode *root = new TreeNode(rootVal);

        // recusive call to find left and right children for current root node
        root -> left = MissingChild(preorder, inorder, start, i-1, Idx);
        root -> right = MissingChild(preorder, inorder, i+1, end, Idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();

        // iterate over preorder
        int Idx = 0;

        return MissingChild(preorder, inorder, 0, n-1, Idx);
    }
};