// T.C = O(2n)      S.C = O(1)

class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) 
        {
            int n = s.length();

            int i = 0;
            int j = 0;

            int curr_cost = 0;
            int max_len = 0;

            while(j < n)
            {
                // calculating cost of converting current characters
                curr_cost += abs(s[j] - t[j]);
            
                while(curr_cost > maxCost)
                {
                    // shrinking the window
                    curr_cost -= abs(s[i] - t[i]);
                    i++;
                }

                max_len = max(max_len, j-i+1);
                j++;
            }

            return max_len;
        }
    };