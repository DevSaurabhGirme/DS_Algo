// t.C = O(n)   S.C = O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long int result_xor = 0;

        // calculating xor of all integers
        for(int & num : nums)
        {
            result_xor = result_xor ^ num;
        }

        // forming mask
        int mask = (result_xor) & (-result_xor);

        // groups to find out the two unique numbers
        int Grp_1 = 0;
        int Grp_2 = 0;

        // performing & with all elements
        for(int &num : nums)
        {
            if((num & mask) != 0)
            {
                // adding to group 1 and calculating xor
                Grp_1 = Grp_1 ^ num;
            }
            else
            {
                // adding to group 2 and calculating xor
                Grp_2 = Grp_2 ^ num;
            }
        }

        return {Grp_1, Grp_2};
    }
};