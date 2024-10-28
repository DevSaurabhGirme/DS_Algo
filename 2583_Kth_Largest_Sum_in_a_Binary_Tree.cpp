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

// T.C = O(height)   S.C =O(n)

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        // heap to store level sum
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;    

        // queue to store level nodes
        queue<TreeNode*> q;
        q.push(root);

        // Performming level-order traversal.
        while(!q.empty())
        {
            // Number of nodes at the current level.
            int n = q.size();
            
            long long levelSum = 0;  

            // Processing one level at a time.
            while (n > 0) 
            {
                TreeNode* nodePopped = q.front();
                q.pop();

                levelSum += nodePopped->val;

                if (nodePopped->left != nullptr) 
                    q.push(nodePopped->left);

                if (nodePopped->right != nullptr) 
                    q.push(nodePopped->right);

                n--;
            }

            min_heap.push(levelSum);

            // Ensuring the heap size does not exceed k.
            if (min_heap.size() > k) 
                min_heap.pop();
        }

        // If there are fewer than k levels, return -1.
        if (min_heap.size() < k) 
            return -1;

        // The kth largest level sum.
        return min_heap.top();
    }
};
