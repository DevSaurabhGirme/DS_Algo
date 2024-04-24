// T.C = O(n)   S.C = O(1) 

class Solution {
public:
    int tribonacci(int n) 
    {
        if(n == 0)
        {
            return 0;
        }

        int a = 0;
        int b = 1;
        int c = 1;

        for(int i = 3; i < n+1; i++)
        {
            int t = a + b + c;
        
            a = b;
            b = c;
            c = t;
        }

        return c;
    }
};