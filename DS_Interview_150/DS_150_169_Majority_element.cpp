class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int size = nums.size();

        // candidate for majority
        int major = nums[0];
        // its count initiated to 1
        int count = 1;

        for(int i = 1; i < size; i++)
        {
            // votes become equal for both the candidataes
            if(count == 0)
            {
                // change the majority candidate
                major = nums[i];
                count++;
            }
            else if(nums[i] == major)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        // no need for verification in this code : if an element occurs >[n/2]times 
        // then any other element must be <[n/2] to make total elements to 'n'
        return major;
    }
};