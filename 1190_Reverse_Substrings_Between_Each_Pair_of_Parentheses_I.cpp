// T.C = O(n^2)

class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<int> lengthToSkip;

        string rev_string;

        for(char &ch : s)
        {
            if(ch == '(')
            {
                lengthToSkip.push(rev_string.length());
            }
            else if(ch == ')')
            {
                int l = lengthToSkip.top();
                lengthToSkip.pop();
                reverse(begin(rev_string)+ l, end(rev_string));
            }
            else
            {
                rev_string.push_back(ch);
            }
        }

        return rev_string;
    }
};