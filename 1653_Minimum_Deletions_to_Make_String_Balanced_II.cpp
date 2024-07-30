// T.C = O(n)   S.C = O(2n)

class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.length();
        
        vector<int> left_b(n, 0);
        vector<int> right_a(n, 0);
    
        int count_b = 0;
        for(int i = 0; i < n; i++)
        {
            left_b[i] = count_b;
            if(s[i] == 'b')
            {
                count_b++;
            }
        }

        int count_a = 0;
        for(int i = n-1; i > 0; i--)
        {
            right_a[i] = count_a;
            if(s[i] == 'a')
            {
                count_a++;
            }
        }

        int del_count = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            del_count = min(del_count, left_b[i] + right_a[i]);
        }

        return del_count;
    }
};