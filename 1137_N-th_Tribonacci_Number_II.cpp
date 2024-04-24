// T.C = O(n)   S.C = O(1) 

class Solution {
public:
    int tribonacci(int n) 
    {
        // integer array to store tribonacci for given n integers
        long int table[38];

        table[0] = 0;
        table[1] = 1;
        table[2] = 1;

        // calculate fibonacci number for every i and store it in table
        for(int i = 3; i < 38; i++)
        {
            table[i] = table[i-1] + table[i-2] + table[i-3];
        }

        return table[n];
    }
};