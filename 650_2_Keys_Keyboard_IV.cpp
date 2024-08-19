// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    int minSteps(int n) 
    {
        if(n == 1)
        {
            return 0;
        }

        if(n == 2)
        {
            return 2;
        }

        vector<int> arr(n+1, 0);

        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            int factor = i/2;

            while(factor >= 1)
            {
                if(i % factor == 0)
                {
                    int stepsToPrintFactorNumOfAs = arr[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    arr[i] = stepsToPrintFactorNumOfAs + copy + paste;
                    break;
                }
                else
                {
                    factor--;
                }
            }
        }

        return arr[n];
    }
};