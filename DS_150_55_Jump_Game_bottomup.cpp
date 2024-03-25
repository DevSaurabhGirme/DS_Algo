class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n= nums.size();

        // vector of type boolean that stores true or false according to index
        vector<bool> table(n, false)

        // true: as we are standing on oth index
        table[0] = true;    

        for(int i = 0; i < n; i++)
        {
            //    3     4-1  3  
            for(int j = i-1; j >= 0; j--)
            {
                      // 3             3 + 1       >= 4
                if(table[j] == true && j + nums[j] >= i)
                {
                        //4
                    table[i] = true;
                    break;
                }
            }
        }

        return table[n-1];
    }
};