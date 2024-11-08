class Solution {
public:
    bool canSortArray(vector<int>& nums) 
    {
        //Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfCurrSegment = nums[0];
        int minOfCurrSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) 
        {
            // they belong to same segment
            if(__builtin_popcount(nums[i]) == numOfSetBits) 
            {
                // finding max number of setbits of current segment
                maxOfCurrSegment = max(maxOfCurrSegment, nums[i]);
                // finding min number of setbits of current segment 
                minOfCurrSegment = min(minOfCurrSegment, nums[i]);
            } 
            else
            {  
                // integer belongs to a new segment
                if(minOfCurrSegment < maxOfPrevSegment) 
                {
                    return false;
                }

                // updating the previous segment's max
                maxOfPrevSegment = maxOfCurrSegment;

                // start of new segment
                maxOfCurrSegment = nums[i];
                minOfCurrSegment = nums[i];
                
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }

        // Final check for proper segment arrangement
        if(minOfCurrSegment < maxOfPrevSegment) 
        {
            return false;
        }
        
        return true;
    }
};
