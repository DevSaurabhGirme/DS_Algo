// top-bottom approach(memoization)

class Solution {
public:

    // array named table to store whether position is reachable or not
    int table[10001];

    // helper function
    bool recur(vector<int> &nums, int n, int curr_idx)
    {
        // reached the last index
        if(curr_idx == n-1)
        {
            return true;
        }

        // check if we have already calculated whether it's possible to reach the end
        // starting from the current index
        if(table[curr_idx] != -1)
        {
            // if yes returns stored value in table array
            return table[curr_idx];
        }

        // iterate through every possiblity for current index
        for(int i = 1; i <= nums[curr_idx]; i++)
        {
            // recursive call to 'recur' function
            if(recur(nums, n, curr_idx + i) == true)
            {
                // if possible to reach end return true and set value in table as true
                return table[curr_idx] = true;
            }
        }
        // it not possible to reach end then return false
        return table[curr_idx] = false;
    }

    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        // initialize all the values to -1 of array 'table'
        memset(table, -1, sizeof(table));

        return recur(nums, n, 0);    
    }
};