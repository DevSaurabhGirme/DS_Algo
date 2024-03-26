class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int tank = 0;
        int start = 0;

        int sum_gas = 0;
        int sum_cost = 0;
        for(int i = 0; i < n; i++)
        {
            sum_gas = sum_gas + gas[i];
            sum_cost = sum_cost + cost[i];
        }

        if(sum_gas < sum_cost)
        {
            return -1;
        }

        for(int i = 0; i < n; i++)
        {
            // calculate units of gas that would be remaining after moving to next station
            tank = tank + (gas[i] - cost[i]);

            // if -ve it means we cannot start from that station
            if(tank <= 0)
            {
                // reset current gas units to 0
                tank = 0;

                // update starting position
                start = i + 1;
            }
        }
        // as soon as we get a +ve tank value it means we can start from that station
        // hence return the station index
        return start;
    }
};