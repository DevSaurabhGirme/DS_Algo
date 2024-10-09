// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minSwaps(string s) 
    {
        stack<char> stk;

        for(char &ch : s)
        {
            if(ch == '[')
            {
                stk.push(ch);
            }
            else if(stk.size() > 0)
            {
                stk.pop();
            }
        }

        return (stk.size()+1)/2;
    }
};