// T.C = O(2^n*n)   S.C = O(n)
// pruning

class Solution {
public:
    void Solve(string s, int i, unordered_set<string>& unset, int currCnt, int& maxCnt)
    {
        if(currCnt + (s.length()-i) < maxCnt)
        {
            return;
        }

        if(i >= s.length())
        {
            maxCnt = max(maxCnt, currCnt);
            return;
        }

        for(int j = i; j < s.length(); j++)
        {
            string subs = s.substr(i, j-i+1);

            if(unset.find(subs) == unset.end())
            {
                // do
                unset.insert(subs);
                // explore
                Solve(s, j+1, unset, currCnt+1, maxCnt);
                // undo
                unset.erase(subs);
            }
        }
        
    }

    int maxUniqueSplit(string s) 
    {
        unordered_set<string> unset;
        int maxCnt = 0;
        int currCnt = 0;

        int i = 0;

        Solve(s, i, unset, currCnt, maxCnt);

        return maxCnt;
    }
};