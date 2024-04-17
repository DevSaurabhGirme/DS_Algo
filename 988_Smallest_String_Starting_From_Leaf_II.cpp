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

// T.C = O(n)+O(length of curr_String)  S.C = O(n)

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        queue<pair<TreeNode*, string>> que;

        // oushing the front element
        que.push({root, string(1, char(root -> val + 'a'))});

        // resultant smallest string
        string sString = "";

        while(!que.empty())
        {
            // retrieve the current node and string at that node
            auto[curr_node, curr_String] = que.front();
            que.pop();

            // leaf node found
            if(curr_node -> left == NULL && curr_node -> right == NULL)
            {
                if(sString == "" || sString > curr_String)
                {
                    sString = curr_String;
                }
            }

            // traversing the depth
            if(curr_node->left) {
                que.push({curr_node->left, char(curr_node->left->val + 'a') + curr_String});
            }
            
            if(curr_node->right) {
                que.push({curr_node->right, char(curr_node->right->val + 'a') + curr_String});
            }
            //que.pop();
        }

        return sString;
    }
};

// popping the pair at end of the loop causes execution delay affecting runtime