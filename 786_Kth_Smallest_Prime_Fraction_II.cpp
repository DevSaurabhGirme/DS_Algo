class Solution {
public:
    typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        // {fraction, i, j}
        priority_queue<V, vector<V>, greater<V>> pq; // mi_heap    

        int n = arr.size();

        // iterating and pushing fraction for largest element as denominator
        for(int i = 0; i < n; i++)
        {
            // denominator = (n-1)th element
            pq.push({1.0 * arr[i]/arr[n-1], (double)i, (double)n-1});

        }
        // 1st smallest, 2nd smallest.... k(th)smallest
        int smallest = 1;

        // calculating fraction for remaining largest element as denominator
        while(smallest < k)
        {
            // retrieve the smallest element
            V vect = pq.top();
            // pop it
            pq.pop();

            // index
            int i = vect[1]; // index of smallest element for every loop
            int j = vect[2]-1; // index of largest element for every loop
        
            // pushing fraction for the remaining largest denominators
            pq.push({1.0 * arr[i]/arr[j], (double)i, (double)j});        

            smallest++;
        }
        
        // got the smallest element
        V vect = pq.top();

        int i = vect[1];
        int j = vect[2];

        return {arr[i], arr[j]};
    }
};