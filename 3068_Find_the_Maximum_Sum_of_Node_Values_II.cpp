// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        // vector to hold difference of node's value after performing xor
        vector<int> gain;

        long int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];

            // populating gain vector
            gain.push_back((nums[i] ^ k) - nums[i]);
        }

        // sorting the vector in descending order
        sort(begin(gain), end(gain), greater<int>());

        int n = gain.size();

        // forming pair of nodes as an edge 
        for(int i = 0; i < n-1; i +=2)
        {
            long int pairSum = gain[i] + gain[i+1];

            if(pairSum > 0)
            {
                sum = sum + pairSum;
            }
        }

        return sum;
    }
};