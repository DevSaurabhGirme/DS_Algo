// Bottum-up
// T.C = O(m*n*n)   S.C = O(m*n)

class Solution {
public:
    int CountSteps(int ringIdx, int i, int n)
    {
        // can be refered as clockwise
        int distance = abs(i - ringIdx);
        // can be refered as anti-clockwise
        int wrapAround = abs(n - distance);

        return min(distance, wrapAround);
    }

    int findRotateSteps(string ring, string key) 
    {
        int n = ring.length();
        int m = key.length();

        // 2-D array to store minimum steps for each cell
        vector<vector<int>> t(n+1, vector<int>(m+1, INT_MAX));

        // base case
        for(int ringIdx = 0; ringIdx < n; ringIdx++)
        {
            t[ringIdx][m] = 0;
        }

        // start filling the array from end
        for(int keyIdx = m-1; keyIdx >= 0; keyIdx--)
        {
            for(int ringIdx = 0; ringIdx < n; ringIdx++)
            {
                int minSteps = INT_MAX; 

                // finding keyword from key in ring
                for(int i = 0; i < ring.length(); i++)
                {
                    if(ring[i] == key[keyIdx])
                    {
                        //                 steps for current keyword +  button  + result of remaining keywords
                        int totalSteps = CountSteps(ringIdx, i, n)   +    1     + t[i][keyIdx+1];
                        minSteps = min(minSteps, totalSteps);
                    }

                }
                t[ringIdx][keyIdx] = minSteps;

            }
        }

        return t[0][0];
    }
};