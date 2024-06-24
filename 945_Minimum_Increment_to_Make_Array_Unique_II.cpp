class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        int n = nums.size();
        int moves = 0;

        int maxEl = *max_element(begin(nums), end(nums));

        // to store frequency of integer elements
        vector<int> freq(n+maxEl, 0);

        for(int num : nums)
        {
            freq[num]++;
        }

        for(int i = 0; i < n+maxEl; i++)
        {
            if(freq[i] <= 1)
            {
                continue;
            }

            int extras = freq[i] - 1;

            freq[i+1] += extras;
            freq[i] = 1;

            moves = moves + extras;
        }

        return moves;

    }
};  