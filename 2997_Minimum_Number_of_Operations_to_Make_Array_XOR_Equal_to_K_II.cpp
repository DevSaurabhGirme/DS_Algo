class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        // number of operations
        int ops = 0;

        // xor of all the elements
        int totalXor = 0;

        for(int &num : nums)
        {
            totalXor = totalXor ^ num;
        }

        // xor of all the elements with k
        ops = (totalXor ^ k);

        // count the number of set bits in ops
        return __builtin_popcount(ops);
    }
};