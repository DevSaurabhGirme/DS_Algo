class Solution {
public:
    int trailingZeroes(int n) 
    {
        long long countofZero = 0;

        while(n >= 1)
        {
            // counting occurances of 5 in the given integer's factorial
            // this is equivalant to counting trailing zeroes 
            n = n/5;

            // updating count of zeros based on occurances of 5 in 'n'
            countofZero = countofZero + n; 
        }

        return countofZero;
    }
};