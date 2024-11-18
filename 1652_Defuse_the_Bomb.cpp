// T.C = O(n)   S.C = O(1)

class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) 
        {
            int n = code.size();

            // answer to defuse te bomb
            vector<int> defused(n, 0);

            if(k == 0)
                return defused;

            // window parameters
            int st = 0;
            int en = 0;

            if(k > 0)
            {
                st = 1;
                en = k;
            }
            else
            {
                st = n + k;
                en = n - 1;
            }

            // sum of first k elements
            int windowSum = 0;
            for(int i = st; i <= en; i++)
            {
                windowSum = windowSum + code[i];
            }

            for(int i = 0; i < n; i++)
            {
                defused[i] = windowSum;

                // excluding the element for k will become k+1 if not
                windowSum = windowSum - code[st % n];
                st++;
                
                // including the succeeding element to make k-1 k
                windowSum = windowSum + code[(en+1) % n];
                en++;
            }

            return defused;
        }
    };