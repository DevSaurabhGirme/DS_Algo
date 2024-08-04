// T.C = O(n)   S.C = O(n)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) 
    {
        unordered_map<int, int> freq(1001);

        for(int &num : target)
        {
            freq[num]++;
        }
        
        for(int &num : arr)
        {
            if(freq.find(num) == freq.end())
            {
                return false;
            }

            freq[num]--;
            if(freq[num] == 0)
            {
                freq.erase(num);
            }
        }

        if(freq.size() == 0)
        {
            return true;
        }
        return false;
    }
};