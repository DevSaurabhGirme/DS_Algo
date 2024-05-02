// T.C = O(n)   S.C = O(2001) ~ O(1)

class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        int Arr[2001] = {0};

        int result = -1;

        for(int &num : nums)
        {
            // checking iif counterpart is present or not
            if(Arr[-num + 1000] == 1)
            {
                result = max(result, abs(num));
            }

            // adding original integer to the array
            Arr[num+1000] = 1;
        }
        return result;
    }
};