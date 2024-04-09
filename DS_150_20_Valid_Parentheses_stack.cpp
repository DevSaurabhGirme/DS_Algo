class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stk;

        for(char &ch : s)
        {
            if(stk.empty() || ch == '{' || ch == '[' || ch == '(')
            {
                stk.push(ch);
                continue;
            }

            if(ch == '}')
            {
                // if corresponding opening present
                if(stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(ch == ']')
            {
                // if corresponding opening present
                if(stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(ch == ')')
            {
                // if corresponding opening present
                if(stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }

        }
        return stk.empty();
        
        
    }
};