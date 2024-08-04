class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // min heap
        priority_queue<int, vector<int>, greater<int>> min_h;

        // insert first k integers
        for(int i = 0; i < k; i++)
        {
            min_h.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++)
        {
            // if current integer greater than topmost integer
            if(nums[i] > min_h.top())
            {
                // pop the top integer
                min_h.pop();
                // and insert current integer
                min_h.push(nums[i]);
            }
        }

        // heap has k elements. topmost is the kth element
        return min_h.top();
    }
};