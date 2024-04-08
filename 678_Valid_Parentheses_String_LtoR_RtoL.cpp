class Solution {
public:
    bool checkValidString(string s) 
    {
        int n = s.length();

        int open = 0;
        int close = 0;

        // left to right balancing open brackets
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '*')
            {
                open++;
            }
            else
            {
                open--;
            }

            if(open < 0)
            {
                return false;
            }
        }

        // right to left  balancing closed brackets
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ')' || s[i] == '*')
            {
                close++;
            }
            else
            {
                close--;
            }

            if(close < 0)
            {
                return false;
            }
        }

        return true;
    }
};
