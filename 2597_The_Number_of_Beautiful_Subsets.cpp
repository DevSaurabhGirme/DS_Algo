// T.C = O(2^n)     S.C = O(n)

class Solution {
public:
    int K;
    
    void backTrack(int idx, vector<int> & nums, unordered_map<int, int>& present, int& result)
    {
        if(idx >= nums.size())
        {
            result++;
            return;
        }

        // didn't take
        backTrack(idx+1, nums, present, result);

        // take
        if(!present[nums[idx] - K] && !present[nums[idx] + K]) // present[nums[idx] - K].find() != present.end()
        {
            present[nums[idx]]++; // add to the map
            backTrack(idx+1, nums, present, result);
            
            present[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) 
    {
        int result = 0;
        K = k;

        unordered_map<int, int> present;

        backTrack(0, nums, present, result);

        return result-1;
    }
};