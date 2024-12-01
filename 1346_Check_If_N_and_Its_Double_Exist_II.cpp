// T.C = O(n)   S.C = O(n)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        int n = arr.size();

        unordered_set<int> unset;

        for(int i = 0; i < n; i++)
        {
            if(unset.find(2*arr[i]) != unset.end())
            {
                return true;
            }
            // check if number is divisible then if double of what we need 
            else if(arr[i]%2 == 0 && unset.find(arr[i]/2) != unset.end())
            {
                return true;
            }

            unset.insert(arr[i]);
        }

        return false;
    }
};