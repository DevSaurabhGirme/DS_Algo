// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {   
        int n = nums.size();
        
        vector<int> vec(n*(n-1)/2);

        // calculating distance  
        int Idx = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int distance = abs(nums[i] - nums[j]);
                vec[Idx]++;
                
                Idx++;
            }
        }
        nth_element(begin(vec), begin(vec)+(k-1), end(vec));

        return vec[k-1];
    }
};