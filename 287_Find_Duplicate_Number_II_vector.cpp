// using extra space of a vector

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int len = nums.size();

        // declaring a vector of size nums with elements initiated to 0
        vector<int> freq(len, 0);

        // iterate through nums
        for(int i = 0; i < len; i++)
        {
            // if freq vector has never seen before the currnt integer
            if(freq[nums[i]] == 0)
            {
                // then increment its count to 1
                freq[nums[i]] = 1;
            }
            else
            {
                // if freq vector has seend before this integer than return that particular integer
                return nums[i];
            }
        }
        // if none found then return 0
        // though according to the question constraint it is not possible
        return 0;
    }
};