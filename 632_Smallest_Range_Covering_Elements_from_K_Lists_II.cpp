// T.C = O(n*log(k))    S.C = O(n)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int k = nums.size();
        
        // min_heap to store
        // {the element, index of the list it belongs to, index of that element in the list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> info_heap;

        int maxEl = INT_MIN;

        for(int i = 0; i < k; i++)
        {
            info_heap.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> finalRange = {-100000, 100000};

        while(!info_heap.empty())
        {
            vector<int> curr = info_heap.top();
            info_heap.pop();

            int ele     = curr[0];
            int listIdx = curr[1];
            int eleIdx  = curr[2];

            if(maxEl - ele < finalRange[1] - finalRange[0]){
                finalRange[0] = ele;
                finalRange[1] = maxEl;
            }

            // looking for better range
            if(eleIdx+1 < nums[listIdx].size())
            {
                int nextEle = nums[listIdx][eleIdx+1];
                info_heap.push({nextEle, listIdx, eleIdx+1});
                
                maxEl = max(maxEl, nextEle);
            }
            else
            {
                break;
            }
        }

        return finalRange;    
    }
};