
class Solution {
public:
    int findComplement(int num) 
    {
        int numOfBits = (int)(log2(num)) + 1;

        unsigned int mask = (1U << numOfBits) - 1;

        return num ^ mask;
    }
};