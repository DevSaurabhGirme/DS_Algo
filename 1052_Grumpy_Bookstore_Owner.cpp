class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size();

        int unsatCust = 0;

        int maxUnsatCust = 0;

        // maximum unsatisfied customers for first window
        for(int i = 0; i < minutes; i++)
        {
            unsatCust += customers[i] * grumpy[i];
        }

        // finding unsatisfied for next mindows in customers
        
        maxUnsatCust = unsatCust;
        int i = 0;
        int j = minutes;

        while(j < n)
        {
            // introducing new element
            unsatCust += customers[j] * grumpy[j];
            // removing element out of window
            unsatCust -= customers[i] * grumpy[i];
    
            maxUnsatCust = max(unsatCust, maxUnsatCust);

            i++;
            j++;
        }

        int totalSat = maxUnsatCust;
        for(int i = 0; i < n; i++)
        {
            // counting satisfied customers
            if(grumpy[i] == 0)
            {
                totalSat += customers[i];  //  totalSat += customers[i] * grumpy[i]
            }
        }

        return totalSat;
    }
};