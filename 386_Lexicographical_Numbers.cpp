// T.C = O(n)   S.C = O(depth)

class Solution {
public:
    void Recur(int curr_num, int n, vector<int>& result)
    {
        if(curr_num  > n)
            return;

        result.push_back(curr_num);

                // 1 ........... 9
        //        / \           /  \
        //       10  11        90   91
        //      /     \
        //     100    110 

        for(int app = 0; app < 10; app++)
        {
            int new_num = curr_num*10 + app;

            if(new_num > n)
                return;

            Recur(new_num, n, result);
        }
   
    }


    vector<int> lexicalOrder(int n) 
    {
        vector<int> result;

        for(int num = 1; num < 10; num++)
        {
            Recur(num, n, result);
        }

        return result;
    }
};