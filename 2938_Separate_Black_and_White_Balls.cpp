class Solution {
public:
    long long minimumSteps(string s) 
    {
        int n = s.length();

        long int swaps = 0;
        int blacks = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                swaps += blacks;
            }
            else
            {
                // counting number of swaps for upcoming 0
                blacks++;
            }
        }

        return swaps;
    }
};