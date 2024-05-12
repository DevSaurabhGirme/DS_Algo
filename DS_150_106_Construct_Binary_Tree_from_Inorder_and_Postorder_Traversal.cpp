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

    TreeNode* MissingChild(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if(inStart > inEnd)
        {
            return NULL;
        }

        // root is always postoder's last node
        TreeNode *root = new TreeNode(postorder[postEnd]);
    
        // finding root in inorder
        int i = inStart;

        for(; i <= inEnd; i++)
        {
            if(inorder[i] == root -> val)
            {
                break;
            }
        }
        // finding number of children on left of root
        int leftSize = i-inStart;
        // finding number of children on right of root
        int rightSize = inEnd-i;

        // recursive calls to find left and right children 
        root -> left = MissingChild(inorder, postorder, inStart, i-1,postStart ,postStart+leftSize-1 );
        root -> right = MissingChild(inorder, postorder, i+1 ,inEnd, postEnd-rightSize ,postEnd-1);
    
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n  = inorder.size();

        int inStart = 0;
        int inEnd = n-1;

        int postStart = 0;
        int postEnd = n-1;

        return MissingChild(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};