// S.C = O(n)   T.C = O(n)

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();

        map<int, int> ordmap;

        for(int &num : nums)
        {
            ordmap[num]++;
        }

        int Idx = 0;

        for(auto &pair : ordmap)
        {
            int num = pair.first;
            int freq = pair.second;

            while(freq > 0)
            {
                nums[Idx] = num;
                freq--;
                Idx++;
            }
        }
    }
};