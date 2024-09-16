// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        unordered_map<string, int> stateMap;

        // vector denoting even or odd occurences as 0 and 1
        vector<int> state(5, 0); 

        string currState = "00000";
        stateMap[currState] = -1;

        int result = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                state[0] = (state[0] + 1) % 2;
            }
            else if(s[i] == 'e')
            {
                state[1] = (state[1] + 1) % 2;
            }
            else if(s[i] == 'i')
            {
                state[2] = (state[2] + 1) % 2;
            }
            else if(s[i] == 'o')
            {
                state[3] = (state[3] + 1) % 2;
            }
            else if(s[i] == 'u')
            {
                state[4] = (state[4] + 1) % 2;
            }

            currState = "";

            // convert current state to string
            for(int j = 0; j < 5; j++)
            {
                currState += to_string(state[j]);
            }

            if(stateMap.find(currState) != stateMap.end())
            {
                result = max(result, i - stateMap[currState]);
            }
            else
            {
                stateMap[currState] = i;
            }
        }

        return result;
    }
};