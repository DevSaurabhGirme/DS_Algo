// T.C = O(n)   S.C = O(1)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) 
    {
        vector<int> arr_freq(1001);
        vector<int> target_freq(1001);

        for(int &num : target)
        {
            target_freq[num]++;
        }
        
        for(int &num : arr)
        {
            arr_freq[num]++;
        }

        for(int i = 0; i < 1001; i++)
        {
            if(arr_freq[i] != target_freq[i])
            {
                return false;
            }
        }

        return true;
    }
};