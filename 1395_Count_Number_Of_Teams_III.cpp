// T.C = O(n)   S.C = O(n^2)

class Solution {
public:
    int dp[1002][1002][4];

    int Ascend(int curr_i , int prev ,int taken , vector<int> &arr)
    {
        if(taken > 3)  
        {
            return 0;
        }

        if(curr_i == arr.size()) 
        {
            // team formed
            if(taken == 3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // already calculated
        if(dp[curr_i][prev][taken]!=-1)  
        {
            return dp[curr_i][prev][taken];
        }

        int tk = 0;

        if(prev == arr.size()+1 || arr[prev] < arr[curr_i])
        {
            // current soldier included
            tk = Ascend(curr_i + 1 , curr_i , taken+1 , arr);
        }

        // current soldier not included
        int ntk = Ascend(curr_i+1 , prev , taken ,arr);

        return dp[curr_i][prev][taken] = tk + ntk;
    }

    int Descend(int curr_i , int prev ,int taken , vector<int> &arr)
    {
        if(taken > 3)   
        {
            return 0;
        }
    
        if(curr_i == arr.size()) 
        {
            if(taken == 3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    
        if(dp[curr_i][prev][taken]!=-1)  
        {
            return dp[curr_i][prev][taken];
        }

        int tk = 0;

        if(prev == arr.size()+1 || arr[prev] > arr[curr_i])
        {
            tk = Descend(curr_i+1 , curr_i , taken +1 , arr);
        }

        int ntk = Descend(curr_i+1 , prev , taken ,arr);

        return dp[curr_i][prev][taken] = tk + ntk;
    }


    int numTeams(vector<int>& arr) 
    {
        int n = arr.size();

        // initialized to -1
        memset(dp , -1 ,sizeof(dp));
        int a = Ascend(0 , n+1 , 0 , arr);

        // reinitialized to -1
        memset(dp , -1 ,sizeof(dp));
        int b = Descend(0 , n+1 , 0 ,arr);

        return a + b;
    }
};