class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // to store the number
        unordered_set<int> dumb;

        int l = 0;
        int r = 0;

        while(r < n)
        {
            if(abs(l - r) > k)
            {
                // remove the number from set
                dumb.erase(nums[l]);
                // shrink the window
                l++;
            }

            // abs(l-r) <= k and present in the set
            if(dumb.find(nums[r]) != dumb.end())
            {
                return true;
            }
            
            // first appearance
            dumb.insert(nums[r]);
            // expand the window
            r++;
        }

        return false;
    }
};