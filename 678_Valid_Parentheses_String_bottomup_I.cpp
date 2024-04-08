class Solution {
public:
    bool checkValidString(string s) {

        int n = s.length();
    
        // 2-D DP array
        vector<vector<bool>> t(n+1, vector<bool>(n+1, false));
        // t[i][open]

        // we are starting from n-1 to find the same from n
        // but we haven't calculated for n yet
        // hence
        t[n][0] = true;  // because at n open brackets is also 0 for empty string 

        for(int i = n-1; i >= 0; i--)
        {
            for(int open = 0; open <= n; open++)
            {
                bool isValid = false;

                /*if(i == n)
                {
                    if(open == 0)
                    {
                        true;
                    }
                    else
                    {
                        false;
                    }
                }*/

                if(s[i] == '*')
                {
                    isValid |= t[i+1][open+1]; // * as '('

                    if(open > 0)
                    {
                        isValid |= t[i+1][open-1]; // * as ')'
                    }
                    
                    isValid |= t[i+1][open]; // * as ''
                }
                else if(s[i] == '(')
                {
                    isValid |= t[i+1][open+1];
                }
                else if(open > 0)
                {
                    isValid |= t[i+1][open - 1];
                }
                t[i][open] = isValid;
            }
        }
        // starting from i=n-1 to i=0 if open == 0 ie no open brackets are left
        // then return true else return false
        // second[] means whether open == 0 or not 
        // we can also say that starting from last index traversing to the 
        // first index we calculated number of open brackets we saw
        // and finally at index 0 we see whether we have 0 or more open brackets remaining 
        return t[0][0];
    }
};
