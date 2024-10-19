// T.C = O(n)   S.C = O(n)

class Solution {
public:
    char findKthBit(int n, int k) 
    {   
        if(n == 1)
        {
            return '0';
        }

        // (1  << n)
        int len = pow(2, n)-1;

        // S(n-1) called for Sn
        if(k < ceil(len/2.0))
        {
            return findKthBit(n-1, k);
        }    
        else if(k == ceil(len/2.0))
            return '1';
        else

        {
            char ch = findKthBit(n-1, len-(k-1));
            return (ch == '0') ? '1' : '0';
        } 
    
    }
};