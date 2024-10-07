// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minLength(string s) 
    {
        stack<char> charStk;

        for(char &ch : s)
        {
            if(!charStk.empty() &&
              ((charStk.top() == 'A' && ch == 'B') ||
              (charStk.top() == 'C' && ch == 'D')))
            {
                charStk.pop();
            }
            else
            {
                charStk.push(ch);
            }
        }

        return charStk.size();
    }
};