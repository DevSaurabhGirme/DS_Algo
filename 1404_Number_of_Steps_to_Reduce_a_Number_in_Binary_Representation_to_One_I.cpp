class Solution {
public:
    void addOne(string &s)
    {
        int m = s.length()-1;

        // traverse from back and flip '1' to '0'
        while(m >= 0 && s[m] != '0')
        {
            s[m] = '0';
            m--;
        }

        if(m < 0)
        {
            s = '1' + s;
        }
        else{
            s[m] = '1';
        }
    }

    int numSteps(string s) 
    {
        // count of number of operations
        int Op = 0;

        while(s.length() > 1)
        {
            int n = s.length();

            if(s[n-1] == '0')
            {
                // number is even
                s.pop_back();
            }
            else
            {
                // number is odd
                addOne(s);
            }
            // operation performed
            Op++;
        }

        return Op;
    }
};