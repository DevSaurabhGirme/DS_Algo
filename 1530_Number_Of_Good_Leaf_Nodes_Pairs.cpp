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

// T.C = O(n^2)     S.C = O(n)
class Solution {
public:
    // build the graph from the tree for nodes traversal 
    void buildGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& graph, unordered_set<TreeNode*>& leaf_nodes)
    {
        if(root == NULL)
        {
            return;
        }

        // leaf node found
        if(root -> left == NULL && root -> right == NULL)
        {
            leaf_nodes.insert(root);
        }

        // connecting the nodes bi-directionally
        if(prev != NULL)
        {
            graph[root].push_back(prev);
            graph[prev].push_back(root);
        }

        buildGraph(root -> left, root, graph, leaf_nodes);
        buildGraph(root -> right, root, graph, leaf_nodes);
    }

    int countPairs(TreeNode* root, int distance) 
    {
        // graph
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        // leaf nodes
        unordered_set<TreeNode*> leaf_nodes;

        buildGraph(root, NULL, graph, leaf_nodes);
    
        int count = 0;

        for(auto &leaf : leaf_nodes)
        {
            // storing nighboring nodes
            queue<TreeNode*> que;
            // marking as visited
            unordered_set<TreeNode*> visited;

            que.push(leaf);
            visited.insert(leaf);

            // BFS
            for(int lvl = 0; lvl <= distance; lvl++)
            { 
                // neighbouring nodes
                int size = que.size();

                while(size--)
                {
                    TreeNode* curr = que.front();
                    que.pop();

                    if(curr != leaf && leaf_nodes.count(curr))
                    {
                        count++;
                    }

                    for(auto &nbr : graph[curr])
                    {
                        if(!visited.count(nbr))
                        {
                            que.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
        }

        return count/2;
    
    }
};