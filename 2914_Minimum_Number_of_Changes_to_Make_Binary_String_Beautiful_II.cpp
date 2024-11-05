// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minChanges(string s) 
    {
        int changes = 0;
    
        int n = s.length();

        // consider 2 consecutive characters at a time
        for (int i = 0; i < n; i+=2) 
        {
            // if not same cange must be made
            if (s[i] != s[i + 1]) 
            {
                changes++;
            }
        }

        return changes;
    }
};