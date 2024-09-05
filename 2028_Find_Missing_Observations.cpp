class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int m = rolls.size();
        int sumOfmRolls = 0;

        for(int& roll : rolls)
        {
            sumOfmRolls += roll;
        }

        // sum of missing n observations
        int sumOfMissing_n = (mean*(m+n)) - sumOfmRolls;

        // to store missing n observations
        vector<int> missing_n;

        // if sum itself is less than n or greater than possible valid sum
        if(sumOfMissing_n < n || sumOfMissing_n > (n*6))
        {
            return {};
        }
        else
        {
            // possible face value
            int n1 = sumOfMissing_n / n;

            int n2 = sumOfMissing_n % n;

            for(int i = 0; i < n; i++)
            {
                // distribute face values evenly
                if(n2 > 0)
                {
                    // balancing the fractional value
                    missing_n.push_back(n1+1);
                }

                // if divisible then n1 is best possibility for the face value
                else
                {
                    missing_n.push_back(n1);

                }

                // after balancing the fractional value decrement remaining part of possible value
                n2 = max(0, n2 - 1);
            }


        }

        return missing_n;
    }
};