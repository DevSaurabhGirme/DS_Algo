// T.C = o(n^2)     S.C = O(n)  TLE

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int width = 0;
        int n = nums.size();

        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] <= nums[j])
                {
                    width = max(width, j-i);
                }
            }
        }    

        return width;
    }
};