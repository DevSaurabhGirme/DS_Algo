// T.C = O(n)   S.C = O(1)

class Solution {
public:
    bool canChange(string start, string target) 
    {
        int n = start.length();
        int i = 0;
        int j = 0;

        while(i < n || j < n) 
        {
            // if blank space at starting itself
            while(i < n && start[i] == '_') 
            {
                i++;
            }

            while(j < n && target[j] == '_') 
            {
                j++;
            }

            // reached end
            if(i == n || j == n) 
            {
                return i == n && j == n;
            }

            if(start[i] != target[j]) 
            {
                return false;
            }

            if(start[i] == 'L' && i < j) 
            {
                return false;
            }

            if(start[i] == 'R' && i > j) 
            {
                return false;
            }

            i++;
            j++;
            
        }

        return true;
    }
};