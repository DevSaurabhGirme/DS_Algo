
class Solution {
public:

    // 2-D array for 2 variables idx and open
    int T[101][101];

    bool Solve(int idx, int open, string &s, int n)
    {
        if(idx == n)
        {
            // reached end of the string and all ( are been balanced out
            // hence return true
            return open == 0;
        }

        if (T[idx][open] != -1)
        {
            // if(T[idx][open] == 0{return true} else{return false})
            return T[idx][open];
        }

        bool isValid = false;

        if(s[idx] == '*')
        {
            // assuming * as (
            isValid |= Solve(idx+1, open+1, s, n);

            // assuming * as empty
            isValid |= Solve(idx+1, open,s, n);

            // assuming * as ) 
            if(open > 0)
            {
                isValid |= Solve(idx+1, open-1, s, n);
            }
        }
        else if(s[idx] == '(')
        {
            isValid = Solve(idx+1, open+1, s, n);
        }
        else if(open > 0)
        {
            isValid |= Solve(idx+1, open-1, s, n);
        }

        // we perform OR operation among all the results returned
        return T[idx][open] = isValid;

    }

    bool checkValidString(string s) 
    {
        int n = s.length();

        memset(T,-1, sizeof(T));

        // Solve(index,open's count, string, number of elements in s) 
        return Solve(0 ,0 ,s, n);
    }
};
