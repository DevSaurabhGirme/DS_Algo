class Solution {
public:
    int maxDepth(string s) 
    {
        int openBrackets = 0;

        // depth of parentheses
        int answer = 0;

        for(int i = 0;i < s.length(); i++)
        {
            char ch = s[i];

            if(ch == '(')
            {
                openBrackets++;
            }
            else if(ch == ')')
            {
                openBrackets--;
            }

            answer = max(answer, openBrackets);
        }

        return answer;
    }
};