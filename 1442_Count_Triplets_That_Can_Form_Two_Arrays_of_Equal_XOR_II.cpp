class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int n = arr.size();

        // count of triplets
        int trips = 0;

        for(int i = 0; i < n; i++)
        {
            // xor from i to j-1
            int a = 0;

            for(int j = i+1; j < n; j++)
            {
                a = a ^ arr[j-1];
                
                // xor from j to k
                int b = 0;

                for(int k = j; k < n; k++)
                {
                    b = b ^ arr[k];
                    if(a == b)
                    {
                        trips++;
                    }
                }
            }
        }

        return trips;
    }
};