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
    void inOrder(TreeNode* root, vector<int>& in_vec)
    {
        if(root == NULL)
        {
            return;
        }

        // exploring left subtree
        inOrder(root -> left, in_vec);
        // root
        in_vec.push_back(root -> val);
        // exploring right subtree
        inOrder(root -> right, in_vec);

    }

    TreeNode* Construct(int l, int r, vector<int> in_vec)
    {
        if(l > r)
        {
            return NULL;
        }
        
        int mid = l+(r-l)/2;

        TreeNode* root = new TreeNode(in_vec[mid]);

        root -> left = Construct(l, mid-1, in_vec);
        root -> right = Construct(mid+1, r, in_vec);

        return root;
    };

    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> in_vec;

        inOrder(root, in_vec);
    
        int l = 0;
        int r = in_vec.size()-1;

        return Construct(l, r, in_vec);
    }
};