// T.C = O(n)   S.C = O(1) 

class Solution {
public:
    int table[38];

    int Calc_Trib(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n ==1 || n == 2)
        {
            return 1;
        }

        // fibonacci number already calculated
        if(table[n] != -1)
        {
            return table[n];
        }

        int a = Calc_Trib(n-1);
        int b = Calc_Trib(n-2);
        int c = Calc_Trib(n-3);

        return table[n] = a+b+c;
    }

    int tribonacci(int n) 
    {
        // initialze our memo integer array table
        memset(table, -1, sizeof(table));

        return Calc_Trib(n);
    }
};