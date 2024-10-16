// T.C = O(n*k)    S.C = O(n)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int k = nums.size();

        // to store indexes of integers to be considered for range
        vector<int> vecListIdx(k+1, 0);

        vector<int> finalRange = {-1000000, 1000000};

        while(1)
        {
            int minEl = INT_MAX;
            int maxEl = INT_MIN;

            int minElListIdx = 0;

            for(int i = 0; i < k; i++)
            {
                // list among nums
                int listIdx = i;
                // element's index from listIdx
                int elIdx = vecListIdx[i];
                // the element itself 
                int ele = nums[listIdx][elIdx];

                // if current element is less than minimum
                if(ele < minEl)
                {
                    // update
                    minEl = ele;
                    minElListIdx = listIdx;
                }

                // update maximum element
                maxEl = max(maxEl, ele);
            }

            // updating the range
            if(maxEl - minEl < finalRange[1] - finalRange[0])
            {
                finalRange[0] = minEl;
                finalRange[1] = maxEl;
            }

            // incrementing listpointer with minimum element
            int nextIdx = vecListIdx[minElListIdx]+1;
            // goes outofbound 
            if(nextIdx >= nums[minElListIdx].size())
            {
                break;
            }

            vecListIdx[minElListIdx] = nextIdx;
        }

        return finalRange;

    }
};