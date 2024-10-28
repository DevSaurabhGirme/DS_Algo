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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return root;
        }

        // for level traversal
        // stores nodes of each level
        queue<TreeNode*> q;
        q.push(root);

        // to store sum of level 
        vector<int> levelSum;

        while(!q.empty())
        {
            int currLvlSum = 0;
            int n = q.size();

            while(n > 0)
            {
                TreeNode* currNode = q.front();
                q.pop();

                currLvlSum += currNode -> val;
                if(currNode -> left != NULL)
                {
                    q.push(currNode -> left);
                }
                if(currNode -> right != NULL)
                {
                    q.push(currNode -> right);
                }

                n--;
            }

            levelSum.push_back(currLvlSum);
        }

        q.push(root);
        // updating the tree with cousin sum
        root -> val = 0;
        
        // levels
        int i = 1;

        while(!q.empty())
        {
            int n = q.size();

            while(n > 0)
            {
                TreeNode* currNode = q.front();
                q.pop();

                // calculating sibling sum
                int sibSum = (currNode -> left != NULL ? currNode -> left -> val : 0) + 
                             (currNode -> right != NULL ? currNode -> right -> val : 0);

                // left child
                if(currNode -> left != NULL)
                {
                    currNode -> left -> val = levelSum[i] - sibSum;
                    q.push(currNode -> left);
                }
                // right child
                if(currNode -> right != NULL)
                {
                    currNode -> right -> val = levelSum[i] - sibSum;
                    q.push(currNode -> right);
                }

                n--;
            }
            // next level
            i++;
        }
        return root;

    }
};