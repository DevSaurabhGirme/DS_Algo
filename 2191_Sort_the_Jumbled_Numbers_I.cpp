// T.C = O(n+digit)     S.C = O(n+digit)

class Solution {
public:
    string getMappedNum(string &num, vector<int>& mapping)
    {
        string mappedNum = "";

        for(int i = 0; i < num.length(); i++)
        {
            char ch = num[i];
            int no = ch - '0';
            mappedNum += to_string(mapping[no]);
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
            // convert integer to string
            string numStr = to_string(nums[i]);

            // numStr after mapping
            string mappedStr = getMappedNum(numStr, mapping);

            // cast it again to integer
            int mappedNum = stoi(mappedStr);

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