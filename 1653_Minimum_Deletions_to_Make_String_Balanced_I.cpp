// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.length();
        int count = 0;

        stack<char> stk;

        for(int i = 0; i < n; i++)
        {
            if(!stk.empty() && s[i] == 'a' && stk.top() == 'b')
            {
                stk.pop();
                count++;
            }
            else
            {
                stk.push(s[i]);
            }
        }

        return count;
    }
};