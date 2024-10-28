// T.C = O(n)   S.C = O(n)

class Solution {
public:
    // to store level of each node
    int levels[1000001]; 

    // to store height of each node
    int height[100001]; 

    // maixmum height at each level 
    int levelMaxHt[100001];

    // second maixmum height at each level
    int levelSecondMaxHt[100001];

    // function to populate above arrays
    int findHeight(TreeNode* root, int lvl) 
    {
        if(root == NULL) 
        {
            return 0;
        }

        // determinig level of given node
        levels[root -> val] = lvl;

        // determining height of each node
        height[root -> val] = max(findHeight(root -> left, lvl + 1), findHeight(root->right, lvl + 1)) + 1;

        // determining max and second max height for same level
        if(levelMaxHt[lvl] < height[root -> val]) 
        {
            levelSecondMaxHt[lvl] = levelMaxHt[lvl];
            levelMaxHt[lvl] = height[root -> val];
        }
        else if(levelSecondMaxHt[lvl] < height[root -> val]) 
        {
            levelSecondMaxHt[lvl] = height[root -> val];
        }

        return height[root -> val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        findHeight(root, 0);

        // to store final tree heights
        vector<int> result;

        for(int &node : queries) 
        {
            //node = that we have to delete
            int L = levels[node]; // O(1)

            //L + H - 1

            int tempResult = L + (levelMaxHt[L] == height[node] ? levelSecondMaxHt[L] : levelMaxHt[L]) - 1;
            // -1 to get the edge number

            result.push_back(tempResult);
        } 

        return result;
    }
};