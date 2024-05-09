// T.C = O(n logn)    S.C = O(n)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long int result = 0;

        int count = 0;

        // max_heap
        priority_queue<int> pq;

        for(int &happy : happiness)
        {
            pq.push(happy);
        }

        for(int i = 0; i < k; i++)
        {
            int happy = pq.top();
            pq.pop();

            result = result + max(happy - count, 0);

            count++;
        }

        return result;
    }
};