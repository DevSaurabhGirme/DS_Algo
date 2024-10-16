
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

// T.C = O(n)    S.C = O(height)
// using BFS

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }

        // to hold right side node
        vector<int> answer;

        // to store nodes(pointers) level wise
        queue<TreeNode*> que;

        que.push(root);


        while(!que.empty())
        {
            int n = que.size();
            TreeNode* node = NULL;

            while(n != 0)
            {
                node = que.front();
                que.pop();

                // going to next level
                if(node -> left != NULL)
                {
                    que.push(node -> left);
                }
                // going to next level
                if(node -> right != NULL)
                {
                    que.push(node -> right);
                }

                n--;
            }

            answer.push_back(node -> val);
        }

        return answer;    
    }
};