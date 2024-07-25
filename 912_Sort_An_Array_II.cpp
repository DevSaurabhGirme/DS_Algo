// Count sort T.C = O(n+k)  S.C = O(1)

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        unordered_map<int, int> ascend;

        for(int &num : nums)
        {
            ascend[num]++;
        }

        int min_el = *min_element(begin(nums), end(nums));
        int max_el = *max_element(begin(nums), end(nums));
    
        int i = 0;
        for(int num = min_el; num <= max_el; num++)
        {
            while(ascend[num] > 0)
            {
                nums[i] = num;
                i++;
                ascend[num]--;
            }
        }
        return nums;
    }
};