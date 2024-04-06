class Solution {
public:
    int trailingZeroes(int n) 
    {
        long int countofZero = 0;

        int floor = 0;
        unsigned long long k = 5;

        while(n/k >= 1)
        {
            floor = n/k;

            countofZero = countofZero + floor; 

            k = k*5;

        }

        return countofZero;
    }
};

/*
    floor = (n/k) + (n/k) ..... + 1
    where k = k*5
    example: n = 625

    floor = (625/5) + (625/25) + (625/125) + (625/625)
    floor =  125    +    25    +     5     +     1
    floor =  156        
*/