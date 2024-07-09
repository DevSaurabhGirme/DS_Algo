class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        int n = customers.size();
        // total waiting time
        double time_waiting = customers[0][1];

        // first customer order finish time
        int finished_prev = customers[0][0] + customers[0][1];

        // calculating for remaining customers starting from second customer
        for(int i = 1; i < n; i++) 
        {
            // retrieving customer
            vector<int> customer = customers[i];

            // arrival time of current customer
            int arrival_time = customer[0];

            // time of starting to cook the current customer's dish
            // either the time of customer's arrival or 
            // the time of finishing the previous customer's dish
            int start_cook = max(arrival_time, finished_prev);
            
            // time to finish current customer's order
            int end_time = start_cook + customer[1];
            
            // update the finish time of current dish for next customer
            finished_prev = end_time;
            
            // total waiting time for all customers 
            time_waiting = time_waiting + (end_time - arrival_time);
        }

        // return average
        return time_waiting / n;
    }
};