// T.c = O(nlogn)   S.C = O(n)

class Solution {
public:
    int getMappedNum(int num, vector<int>& mapping)
    {
        if(num < 10)
        {
            return mapping[num];
        }

        int mappedNum = 0;
        int pValue = 1;

        while(num != 0)
        {
            int lastDigit = num % 10;
            int mappedDigit = mapping[lastDigit];

            mappedNum += (mappedDigit * pValue);

            pValue *= 10;
            num = num / 10;
        }

        return mappedNum;
        
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        int n = nums.size();

        // vector pair to hold mapped integer and its index 
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++)
        {
            int mappedNum = getMappedNum(nums[i], mapping);

            // mapped integer and its original index
            vec.push_back({mappedNum, i});
        }

        // sort according mappedNum
        sort(vec.begin(), vec.end());

        vector<int> result;

        for(auto &pair : vec)
        {
            int orgIdx = pair.second;
            result.push_back(nums[orgIdx]);
        }
    
        return result;
    }
};