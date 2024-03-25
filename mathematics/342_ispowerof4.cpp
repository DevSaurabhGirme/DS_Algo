// works perfectly

class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        int mask = 0b01010101010101010101010101010101;

        // Checkpoints :

        // 1. n&(n-1) == 0; to authenticate whether given number is power of 4
        // 2. n & mask == n; 
        if((n > 0) && (n & (n - 1)) == 0 && (n & mask) == n)
        {
            return true;
        }
        return false;
    }
};
/*
powers of 4 are a subset of even powers of 2. wef 2^2 = 4; 2^4 = 16. Besides if we convert these powers into their binary form the we see that only single '1' is present only on odds place.
Therefore, if we use a mask having '1' on every odds place and perform bitwise and with given number we are resulted with the same number (n) again!
Perhaps, there is an exception here. There may be an input having more than one "1's" in the odd places. This has same output for above bitwise & operation.
To avoid this we perform bitwise 'and' operation of given number and its preceding number. wef [n & (n-1) == 0]. If we get 0 as output we satisfy the condition.
Now we combine above conditions using && we get the ultimate result as true or false*/