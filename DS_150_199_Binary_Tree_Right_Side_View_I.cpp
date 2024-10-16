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

// T.C = O(n)   S.C = O(height)
// using DFS

class Solution {
public:
    void preTraversal(TreeNode* root, int lvl, vector<int>& answer)
    {
        if(root == NULL)
        {
            return ;
        }

        // number of elements in vector must be same as levels
        if(answer.size() < lvl)
        {
            answer.push_back(root -> val);
        }

        // root -> right -> left
        preTraversal(root -> right, lvl+1, answer);

        preTraversal(root -> left, lvl+1, answer);

    }

    vector<int> rightSideView(TreeNode* root) 
    {
        // to hold right side node
        vector<int> answer;

        //           root, level, vector
        preTraversal(root,   1  , answer);

        return answer;    
    }
};