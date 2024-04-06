class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        unordered_map<int> toRemoveunmap;
        stack<int> stk;
        
        for(int i = 0; i<n; i++) 
        {
            if(s[i] == '(')
            {
                //store index of '('
                stk.push(i);
            }
            else  if(s[i] == ')') 
            {
                if(stk.empty()) 
                { 
                    //invalid ')'
                    toRemoveunmap.insert(i);
                } 
                else 
                {
                    stk.pop(); //balancing with open '('
                }
            }
        }
        
        //suppose the input is  "(("
        //Then, we won't be adding them in the toRemoveunmap map to remove later
        //So, we add them directly to the map and simultaneously remove them from the stack as well
        while(!stk.empty()) 
        {
            toRemoveunmap.insert(stk.top());
            stk.pop();
        }
        
        string result = "";
        
        for(int i = 0; i<n; i++) 
        {
            // if we do not find the character's index until end of the map
            // it means it is a valid one and append it to the result string
            if(toRemoveunmap.find(i) == toRemoveunmap.end())
            {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};