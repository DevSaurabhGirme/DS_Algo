class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char> depth;

        // depth of parentheses
        int answer = 0;

        for(int i = 0;i < s.length(); i++)
        {
            char ch = s[i];

            if(ch == '(')
            {
                depth.push(ch);
            }
            else if(ch == ')')
            {
                depth.pop();
            }

            answer = max(answer,(int)depth.size());
        }

        return answer;
    }
};