class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 0)
        {
            return x;
        }

        int start = 1;
        long int end = x;
    
        long int mid = -1;
        int root = 0;

        while(start <= end)
        {
            mid = start + (end- start)/2;

            if(mid*mid <= x)
            {
                // storing possible answer in root
                root =  mid;
                start = mid + 1;
            }
            else if(mid*mid > x)
            {
                end = mid - 1;
            }
        }

        return root;
    }
};