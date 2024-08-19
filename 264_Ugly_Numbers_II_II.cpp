// min_heap T.C = O(n(logn))    S.C = O(n)

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int arr[3] = {2, 3, 5};

        priority_queue<long long, vector<long long>, greater<long long>> minUglyHeap;

        unordered_set<long long> visited;

        // adding first ugly number to thr heap
        minUglyHeap.push(1);
        // marking it as visited
        visited.insert(1);

        long long curr_ugly = 0;

        for(int i = 0; i < n; i++)
        {
            // retrieve topmost ugly number
            curr_ugly = minUglyHeap.top();
            minUglyHeap.pop();

            for(int &primeFact : arr)
            {
                long long new_ugly = curr_ugly * primeFact;

                // if new ugly number not found in visited set
                if(visited.find(new_ugly) == visited.end())
                {
                    // add it to the heap
                    minUglyHeap.push(new_ugly);
                    // mark as visited
                    visited.insert(new_ugly);
                }
            }
        }

        return curr_ugly;
    }
};