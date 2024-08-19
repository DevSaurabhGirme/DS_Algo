// DP   T.C = O(n)  S.C = O(n)

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        // vector to store ugly numbers
        vector<int> arr(n);

        // initializing arr with 1st ugly number
        arr[0] = 1;    

        // integers pointing to respective ugly numbers
        // (i2)th, (i3)th, (i5)th
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
    
        // calculating next ugly number
        for(int i = 1; i < n; i++)
        {
            int i2_ans = arr[i2] * 2;
            int i3_ans = arr[i3] * 3;
            int i5_ans = arr[i5] * 5;

            arr[i] = min(i2_ans, min(i3_ans, i5_ans));

            // if current ugly number is a result of i2 then
            if(arr[i] == i2_ans)
            {
                // increment
                i2++;
            }
            // if current ugly number is a result of i3 then
            if(arr[i] == i3_ans)
            {
                // increment
                i3++;
            }
            // if current ugly number is a result of i5 then
            if(arr[i] == i5_ans)
            {
                // increment
                i5++;
            }
        }

        return arr[n-1];
    }
};