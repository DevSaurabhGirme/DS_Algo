// Recursion + memoization
// T.C = O(m*(n^2)) S.C = O(n)

class Solution {
public:
    // 2-D array for ringIdx and keyIdx
    int t[101][101];

    int CountSteps(int ringIdx, int i, int n)
    {
        // can be refered as clockwise
        int distance = abs(i - ringIdx);
        // can be refered as anti-clockwise
        int wrapAround = abs(n - distance);

        return min(distance, wrapAround);
    }

    int Solve(int ringIdx, int keyIdx, string& ring, string& key)
    {
        if(keyIdx == key.length())
        {
            return 0;
        }

        // steps alrady calculated
        if(t[ringIdx][keyIdx] != -1)
        {
            return t[ringIdx][keyIdx];
        }

        int minSteps = INT_MAX; 

        // finding keyword from key in ring
        for(int i = 0; i < ring.length(); i++)
        {
            if(ring[i] == key[keyIdx])
            {
                //                  steps for current keyword          +  button  + result of recursive call for remaining keywords
                int totalSteps = CountSteps(ringIdx, i, ring.length()) +    1     + Solve(i, keyIdx+1, ring, key);
                minSteps = min(minSteps, totalSteps);
            }

        }
        return t[ringIdx][keyIdx] = minSteps;

    }

    int findRotateSteps(string ring, string key) 
    {
        // 2-D array initialization
        memset(t, -1, sizeof(t));

        // Solve(12:00, keyword, string ring, string key)
        return Solve(0, 0, ring, key);   
    }
};