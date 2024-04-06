// S.C = O(n) T.C = O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int n = s.length();

        string res = "";
        
        int open = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                open++;
                res.pus_back(s[i]);
            }
            else if(s[i] == ')')
            {
                // if we have extra open brackets for the ')' to balance out
                if(open > 0)
                {
                    // then balace it and
                    open--;
                    // insert it in the result string
                    res.push_back(s[i]);
                }
            }
            else
            {
                res.push_back(s[i]);
            }
        }

        string final_res = "";

        for(int i = res.length()-1; i >= 0; i--)
        {
            if(res[i] == '(' && open > 0)
            {
                open--;
            }
            else
            {
                final_res.push_back(res[i]);
            }
        }
        
        reverse(begin(final_res), end(final_res));

        return final_res;
    }
};