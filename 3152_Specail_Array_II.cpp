// TC = O(m+n)      SC = O(n)

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int m = queries.size();

        // to store cumulative count of indices cannot be a part of special array till index i
        vector<int> parArr(n,0);

        for(int i = 1; i < n; i++)
        {
            // if adjacent integers are even
            if(nums[i]%2 == nums[i-1]%2)
            {
                // updating count of violators
                parArr[i] = parArr[i-1]+1;
            }
            // odd
            else
            {
                // count remains same
                parArr[i] = parArr[i-1];
            }
        }

        // final result whether given query is a special array or not
        vector<bool> answer(m,false);

        int i = 0;
        for(vector<int> query : queries)
        {
            int st = query[0];
            int end = query[1];

            // alternate odds or evens present
            if(parArr[end] - parArr[st] == 0)
            {
                answer[i] = true;
            }
            i++;
        }

        return answer;

    }
};