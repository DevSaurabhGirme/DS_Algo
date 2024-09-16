// T.C = O(n)   S.C = O(32) ~ O(1)

class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        // to maintain states(states and its index)
        unordered_map<int, int> stateMap;

        int mask = 0;

        // initializing the map
        stateMap[mask] = -1;

        int result = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                mask = (mask ^ (1 << 0));
            }
            else if(s[i] == 'e')
            {
                mask = (mask ^ (1 << 1));
            }
            else if(s[i] == 'i')
            {
                mask = (mask ^ (1 << 2));
            }
            else if(s[i] == 'o')
            {
                mask = (mask ^ (1 << 3));
            }   
            else if(s[i] == 'u')
            {
                mask = (mask ^ (1 << 4));
            }

            if(stateMap.find(mask) != stateMap.end())
            {
                // calculating the length
                result = max(result, i - stateMap[mask]);
            }
            else
            {
                stateMap[mask] = i;
            }
        }

        return result;
    }
};