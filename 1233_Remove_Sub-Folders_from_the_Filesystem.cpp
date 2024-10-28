// T.C = O(n*len^2)   S.C = O(n)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        unordered_set<string> unset;

        for(string& currFolder : folder)
        {
            unset.insert(currFolder);
        }
        
        // to store parent folders
        vector<string> result;

        for(string& currFolder : folder) 
        {
            bool isSubFolder = false;
        
            string tempFolder = currFolder;
        
            while(!currFolder.empty()) 
            {
                // auto position = currFolder.find_last_of('/');
                // gives index of mentioned character
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, position);

                if(unset.find(currFolder) != unset.end()) 
                {
                    //currFolder is a sub-folder
                    isSubFolder = true;
                    break;
                }
            }

            if(isSubFolder == false) 
            {
                result.push_back(tempFolder);
            }

        }

        return result;
    }
};