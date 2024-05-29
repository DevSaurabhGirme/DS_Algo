class Solution {
public:
    int numSteps(string s) 
    {
        int n = s.length();

        // count of number of operations
        int Op = 0;
        int carry = 0;

        for(int i = n-1; i >= 1; i--)
        {
            if(((s[i] - '0') + carry) % 2 == 1)
            {
                // odd number
                Op += 2;
                carry = 1;
            }
            else
            {
                // even number
                Op += 1;
            }
        }

        return Op + carry;
    }
};