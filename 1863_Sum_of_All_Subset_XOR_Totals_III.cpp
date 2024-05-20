//T.C = O(2^n)  S.C = O(n)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) 
    {
        int n = nums.size();

        int sum = 0;

        for(int &num : nums)
        {
            sum |= num;
        }

        return sum << (n-1);
    }
};