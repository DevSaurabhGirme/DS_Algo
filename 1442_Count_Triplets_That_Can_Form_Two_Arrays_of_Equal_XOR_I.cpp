class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        vector<int> prefixXor(begin(arr), end(arr));

        // first value of prefix set to 0
        prefixXor.insert(prefixXor.begin(), 0);

        int n = prefixXor.size();

        for(int i = 1; i < n; i++)
        {
            prefixXor[i] = prefixXor[i] ^ prefixXor[i-1];
        }

        int trips = 0;

        for(int i = 0; i < n; i++)
        {
            for(int k = i+1; k < n; k++)
            {
                if(prefixXor[k] == prefixXor[i])
                {
                    // -1due to extra insertion of 0 to prefixXor vector
                    trips += k-i-1;
                }
            }
        }

        return trips;
    }
};