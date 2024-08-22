// T.C = O(log2(num))

class Solution {
public:
    int findComplement(int num) 
    {
        int numOfBits = (int)(log2(num)) + 1;

        for(int i = 0; i < numOfBits; i++)
        {
            num = num ^ (1 << i);
        }

        return num;
    }
};