// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size();

        multiset<int> mst;
    
        int i = 0;
        int j = 0;
        // maximum length of subarray found
        int max_len = 0;

        while(j < n)
        {
            mst.insert(nums[j]);

            while(*mst.rbegin() - *mst.begin() > limit)
            {
                mst.erase(mst.find(nums[i]));
                i++;
            }

            // updating length o subarray
            max_len = max(max_len, j-i+1);
            j++;
        }

        return max_len;
    }
};