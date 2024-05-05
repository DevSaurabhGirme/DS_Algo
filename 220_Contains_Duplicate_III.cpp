// T.C = O(nlogi_Diff)

class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int i_Diff, int v_Diff) 
    {
        int n = nums.size();
        
        set<long long> unset;
        
        for(int i = 0; i < n; i++) 
        {
            // shrink the window
            if(unset.size() > i_Diff) 
            {
                // remove the unwanted integer outside the window
                unset.erase(nums[i - i_Diff- 1]);
            }
            
            long long element = (long long)nums[i] - (long long)v_Diff;
            
            auto it = unset.lower_bound(element);
            
            // check if the absolute difference between nums[i] and 
            // the value pointed by 'it' is within the range v_Diff.
            if(it != end(unset) && abs((long long)nums[i] - (long long)(*it)) <= v_Diff) 
            {
                return true;
            }
            
            unset.insert(nums[i]);
        }
        
        return false;
    }
};