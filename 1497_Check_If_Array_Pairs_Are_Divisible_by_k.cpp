class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        // array to store remainder values
        vector<int> remain(k,0);

        // populating the array
        for(int &num : arr)
        {
            //        handling negative input
            int rem = (num % k + k) % k;
            remain[rem]++;
        }

        // count of integers with 0 as remainder
        if(remain[0] % 2 != 0)
            return false;

        // looking for other half
        for(int rem = 1; rem <= k/2; rem++)
        {
            int other = k - rem;

            // checking frequency
            if(remain[other] != remain[rem])
            {
                return false;
            }
        }

        return true;
    }
};