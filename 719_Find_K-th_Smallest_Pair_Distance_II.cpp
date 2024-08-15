// T.C = O(n^2)     S.C = O(maxEl)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {   
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> diffCount(maxEl+1,0);

        int n = nums.size();
        
        // calculating number of pairs for each distance  
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int distance = abs(nums[i] - nums[j]);
                diffCount[distance]++;
            }
        }

        for(int d = 0; d < maxEl+1; d++)
        {
            k -= diffCount[d];
            if(k <= 0)
            {
                return d;
            }
        }
    
        return -1;
    }
};