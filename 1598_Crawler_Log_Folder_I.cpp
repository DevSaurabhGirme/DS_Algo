class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int depth = 0;

        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i] == "./")
            {
                continue;
            }
            else if(logs[i] == "../")
            {
               depth--;    
            }
            else
            {
                depth++;
            }

            if(depth < 0)
            {
                depth = 0;
            }
        }

        if(depth < 0)
        {
            return 0;
        }

        return depth;
    }
};