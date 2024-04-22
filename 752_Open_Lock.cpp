// T.C = O(n^w)     S.C = O(n^w)
// w = number of wheels

class Solution {
public:

    void findNeighbors(queue<string>& que, string& curr_S, unordered_set<string>& avoid)
    {
        // find valid combinations for each wheel of 4
        // T.C = O(1)
        for(int i = 0; i < 4; i++)
        {
            char ch = curr_S[i];

            char dec = ch == '0' ? '9' : ch-1;
            char inc = ch == '9' ? '0' : ch+1;

            curr_S[i] = dec;

            // T.C = O(1)
            if(avoid.find(curr_S) == avoid.end())
            {
                // not found hence mark as not to visit again
                // by adding it to set
                avoid.insert(curr_S);

                // possible neighbour found
                que.push(curr_S);
            }

            curr_S[i] = inc;

            // T.C = O(1)
            if(avoid.find(curr_S) == avoid.end())
            {
                // not found hence mark as not to visit again
                // by adding it to the set
                avoid.insert(curr_S);

                // possible neighbour found
                que.push(curr_S);
            }

            // reseting the value for next wheel
            curr_S[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) 
    {
        // level 0
        string start = "0000";

        // combinations to avoid failureto reach target including deadends
        // T.C = O(k)   k = numbers of deadlock elements
        unordered_set<string> avoid(begin(deadends), end(deadends));

        // if start itself is to avoided
        if(avoid.find(start) != avoid.end())
        {
            return -1;
        }

        // queue to store all valid neighbor combinations
        queue<string> que;
        que.push(start);

        // level represents all valid combinations as a single move for individual wheel
        int level = 0;

        while(!que.empty())
        {
            // solving for one level at a time
            int n = que.size();

            while(n--)
            {
                string curr_S = que.front();
                que.pop();

                if(curr_S == target)
                {
                    return level;
                }
                
                // finding neighbors for current level lock string
                findNeighbors(que, curr_S, avoid);
            }

            // done finding neighbors for current state or level
            // hence level up
            level++;
        }
        return -1;
    }
};