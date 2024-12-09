// T.C = O(n^2)     S.C ~ O(n^2)

class Solution {
public:
    int n;
    bool Recur(string &start, string &target, unordered_map<string, bool>& unmap) 
    {
        if(start == target) 
        {
            return true;
        }

        //Memoization
        if(unmap.count(start)) 
        {
            return unmap[start];
        }

        for(int i = 0; i < start.length(); i++) 
        {
            if(start[i] == 'L' && i > 0 && start[i-1] == '_') 
            {
                // move
                swap(start[i], start[i-1]);
            
                if(Recur(start, target, unmap) == true) 
                {
                    return true;
                }

                swap(start[i], start[i-1]);
            } 
            else if(start[i] == 'R' && i < n-1 && start[i+1] == '_') 
            {
                swap(start[i], start[i+1]);
            
                if(Recur(start, target, unmap) == true) 
                {
                    return true;
                }

                swap(start[i], start[i+1]);
            }
        }

        return unmap[start] = false;
    }

    bool canChange(string start, string target) 
    {
        n = start.length();
    
        unordered_map<string, bool> unmap;
        
        return Recur(start, target, unmap);
    }
};