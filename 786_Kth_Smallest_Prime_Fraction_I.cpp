class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        // {fraction, arr[i], arr[j]}
        priority_queue<vector<double>> pq;    

        int n = arr.size();

        // iterate to find the fractions
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                double div = (double)arr[i]/arr[j];

                // push into priority queue(max_heap)
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});
            
                // is more than k elements in the queue
                if(pq.size() > k)
                {
                    // pop the topmost element(maximum value)
                    pq.pop();
                }
            }
        }
        
        // retrieve topmost element which is our k-th element
        auto vect = pq.top();
        // vector to store arr[i] and arr[j]
        vector<int> result(2);
        // insert into result vector
        result[0] = vect[1];
        result[1] = vect[2];

        return result;
    }
};