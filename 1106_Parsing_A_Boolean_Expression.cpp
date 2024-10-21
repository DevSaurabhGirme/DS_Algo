// T.C = O(n)   S.C = O(n)

class Solution {
public:
    char solveOp(vector<char>& boo, char Op)
    {
        if(Op == '!')
        {
            return boo[0] == 't' ? 'f' : 't';
        }

        if(Op == '&')
        {
            for(char &ch : boo)
            {
                if(ch == 'f')
                    return 'f';
            }

            return 't';
        }

        if(Op == '|')
        {
            for(char &ch : boo)
            {
                if(ch == 't')
                    return 't';
            }

            return 'f';
        }

        return 'f';
    }

    bool parseBoolExpr(string exp) 
    {
        int n = exp.length();

        stack<char> stk;

        for(int i = 0; i < n; i++)
        {
            if(exp[i] == ',')
                continue;

            if(exp[i] == ')')
            {
                vector<char> boo;

                // ')' encountered so operate over the exp
                // from '(' was seen
                while(stk.top() != '(')
                {
                    // insert into vector for further use
                    boo.push_back(stk.top());
                    stk.pop();
                }

                stk.pop();
                // operator encountered
                // !, &, |
                char Op = stk.top();
                stk.pop();

                // call to the function to solve the found expersion
                stk.push(solveOp(boo, Op));
            }
            else
            {
                stk.push(exp[i]);
            }
        }

        return stk.top() == 't' ? true : false;
    }
};