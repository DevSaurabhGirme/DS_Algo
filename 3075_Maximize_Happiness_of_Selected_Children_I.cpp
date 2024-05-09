// T.C = O(n logn)    S.C = O(1)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        // sort in descending order
        sort(begin(happiness), end(happiness), greater<int>());
    
        long int result = 0;
    
        // number of children with maximum happiness selected
        int count = 0;

        for(int i = 0 ;i < k; i ++)
        {
            result= result + max(happiness[i] - count, 0);

            count++;
        }

        return result;
    }
};