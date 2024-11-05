// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minChanges(string s) 
    {
        int n = s.length();

        char ch = s[0];
        int cnt = 0;
        int changes = 0;

        for(int i = 0; i < n; i++)
        {
            // same character found
            if(s[i] == ch)
            {
                cnt++;
                continue;
            }

            // found different character
            // if previous substring is of even length 
            if(cnt % 2 == 0)
            {
                // start a new substring
                cnt = 1;
            }
            // substring of odd length so making change is must
            else
            {
                changes++;
                cnt = 0;
            }

            // reassigning for further iterations
            ch = s[i];
        }

        return changes;
    }
};