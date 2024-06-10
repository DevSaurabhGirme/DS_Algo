// T.C = O(nlogn)

class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int> expected;

        expected = heights;

        sort(expected.begin(), expected.end());

        int n = expected.size();
        int iCnt = 0;

        for(int i = 0; i < n; i ++)
        {
            if(expected[i] != heights[i])
            {
                iCnt++;
            }
        }
        return iCnt;
    }
};