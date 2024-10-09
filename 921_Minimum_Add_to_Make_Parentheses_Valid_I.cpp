// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char> stk;

        int reqOpen = 0;

        for(char &ch : s)
        {
            if(ch == '(')
            {
                stk.push(ch);
            }
            else if(!stk.empty())
            {
                stk.pop();
            }
            else
            {
                reqOpen++;
            }
        }

        return reqOpen + stk.size();
    }
};