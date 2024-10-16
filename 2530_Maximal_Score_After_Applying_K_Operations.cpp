class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        // to store integers of nums for quick largest element retrieval
        priority_queue<int> max_heap;

        for(int &num : nums)
        {
            max_heap.push(num);
        }

        long int score = 0;

        while(k != 0)
        {
            int maxEl = max_heap.top();
            max_heap.pop();
            // step 2
            score += maxEl;

            // step 3 : adding new integer to heap
            int newEl = int(ceil(maxEl / 3.0));
            max_heap.push(newEl);

            k--;
        }

        return score;
    }
};