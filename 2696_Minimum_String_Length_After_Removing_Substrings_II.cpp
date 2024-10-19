// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minLength(string s) 
    {
        int n = s.length();

        int i = 0;
        int j = 1;
    
        while(j < n)
        {   
            // if i goes negative
            if(i < 0)
            {
                i++;
                s[i] = s[j];
            }
            else if((s[i] == 'A' && s[j] == 'B') ||
               (s[i] == 'C' && s[j] == 'D'))
            {
                i--;
            }
            else
            {
                // rewriting
                i++;
                s[i] = s[j];
            }

            j++;
        }

        return i+1;
    }
};