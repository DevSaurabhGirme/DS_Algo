// doesn't work

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        set<int> ascend;

        for(int &num : nums)
        {
            ascend.insert(num);
        }

        vector<int> sortedArr;

        for(auto it : ascend)
        {
            sortedArr.push_back(it);
        }

        return sortedArr;
    }
};