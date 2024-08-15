// TLE

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {   
        vector<int> pairDistArr;

        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                pairDistArr.push_back(abs(nums[i] - nums[j]));
            }
        }

        sort(pairDistArr.begin(),pairDistArr.end());
        
        return pairDistArr[k-1];
    }
};