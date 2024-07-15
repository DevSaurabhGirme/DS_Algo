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
// T.C = O(n)   S.C = O(n)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        // stores node and its corresponding address
        unordered_map<int, TreeNode*> parents;
        // set of children
        unordered_set<int> children;
    
        for(vector<int>& vec : descriptions)
        {
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            // create node for parent if not already
            if(parents.find(parent) == parents.end())
            {
                parents[parent] = new TreeNode(parent);
            }

            // create node for child if not already
            if(parents.find(child) == parents.end())
            {
                parents[child] = new TreeNode(child);
            }

            if(isLeft == 1)
            {
                parents[parent] -> left = parents[child];
            }
            else
            {
                parents[parent] -> right = parents[child];
            }

            children.insert(child);
        }

        for(vector<int>& vec : descriptions)
        {
            int parent = vec[0];
            if(children.find(parent) == children.end())
            {
                return parents[parent];
            }
        }

        return NULL;

    
    }
};