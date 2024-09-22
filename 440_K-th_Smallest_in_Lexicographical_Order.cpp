// T.C = O(log n)   S.C = O(depth) or O(n)

class Solution {
public:
    int Count(long int curr, long int next, int n)
    {
        // total count of integers in each level
        int numCount = 0;

        while(curr <= n)
        {
            // count in each level
            numCount = numCount + (next - curr);

            // moving to next level
            curr = curr*10;
            next = next*10;

            next = min(next, long(n+1));
        }

        return numCount;
    }

    int findKthNumber(int n, int k) 
    {
        int curr = 1;
        // 1 is always included
        k = k - 1;

        while(k != 0)
        {
            int totalCount = Count(curr, curr+1, n);

            if(totalCount <= k)
            {
                curr++;
                // skip integers under curr prefix
                k = k - totalCount;
            }
            else
            {
                // going deep in same prefix tree
                curr = curr * 10;
                k -= 1;
            }
        }

        return curr;
    }
};