// T.C = O(n)   S.C = O(1)

class Solution {
public:
    long long minEnd(int n, int x) 
    {
        int num = x;

        for(int i = 1; i < n; i++) 
        {
            // performing OR with num+1 to now the actual next element
            num = (num+1) | x;
        }

        return num;
    }
};