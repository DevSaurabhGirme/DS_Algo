class Solution{
public:
    vector<string> getTokens(string version)
    {
        // string converted into stream
        stringstream ss(version);

        // store individual token
        string token = "";

        // to store tokens
        vector<string> tokens;

        // from stream ss break it into tokens, store on token based on '.'
        while(getline(ss, token, '.'))
        {
            tokens.push_back(token);    
        }
        return tokens;
    }

    int compareVersion(string version1, string version2)
    {
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);   

        int m = v1.size();
        int n = v2.size(); 
        int i = 0;

        while(i < m || i < n)
        {
            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;
        
            if(a < b)
            {
                return -1;
            }
            else if(a > b)
            {
                return 1;
            }
            else
            {
                i++;
            }
        }
        // versions are equal
        return 0;
    }
};