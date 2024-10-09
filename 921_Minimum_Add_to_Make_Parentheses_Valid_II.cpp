// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int size = 0;

        int reqOpen = 0;

        for(char &ch : s)
        {
            if(ch == '(')
            {
                size++;
            }
            else if(size != 0)
            {
                size--;
            }
            else
            {
                reqOpen++;
            }
        }

        return reqOpen + size;
    }
};