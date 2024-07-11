// T.C = O(n+n)

class Solution {
public:
    string reverseParentheses(string s) 
    {
        int n = s.length();

        stack<int> openPar;
        vector<int> door(n);

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                openPar.push(i);
            }
            else if(s[i] == ')')
            {
                // retrieve index of latest closing parenthesis
                int j = openPar.top();
                openPar.pop();

                // jump between closing and opening parenthesis
                door[i] = j;
                door[j] = i;
            }
        }

        string result;
        int flag = 1;

        for(int i = 0; i < n; i += flag)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                i = door[i];
                // L -> R or // R -> L
                flag = -flag; // changing direction
            }
            else
            {
                result.push_back(s[i]);
            }
        }

        return result;

    }
};