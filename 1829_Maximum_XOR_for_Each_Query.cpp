// T.C = O(n)   S.C = O(n)

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int n = nums.size();

        vector<int> answer(n);

        // calculating XOR of nums array
        int XOR = 0;
        for(int i = 0; i < n; i++)
        {
            XOR = XOR ^ nums[i];
        }

        // calculating the bitset mask
        // int mask = 2^maximumBit - 1;

        int mask = (1 << maximumBit) - 1;

        // calculating flipped value i.e k
        for(int i = 0; i < n; i++)
        {
            int k = XOR ^ mask;
            answer[i] = k;

            XOR = XOR ^ nums[n-i-1];
        }

        return answer;
    }
};