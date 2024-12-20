// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // to store range of each num in nums after the operation
        vector<pair<int,int>> ranges;

        for(int &num : nums)
        {
            ranges.push_back({num-k, num+k});
        }

        sort(ranges.begin(), ranges.end());

        // to store ending of each pair
        deque<int> endings;

        // max length of beautiful subsequence
        int maxLen = 0;

        for(auto &range : ranges)
        {
            // no overlapping
            if(!endings.empty() && endings.front() < range.first)
            {
                // remove from the group of overlapping ranges
                endings.pop_front();
            }
            // overlapping
            endings.push_back(range.second);

            maxLen = max(maxLen, (int)endings.size());
        }

        return maxLen;
    }
};