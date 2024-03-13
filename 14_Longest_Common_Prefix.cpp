class Solution {
public:
    string longestCommonPrefix(vector<string>& strvec) 
    {
        // answer string to store prefix
        string answer = "";

        // sort given strings in alphabetical order
        sort(strvec.begin(), strvec.end());

        // strores number of strings in the vector array
        int vSize = strvec.size();

        // variables to store the first and last string in the array
        string first = strvec[0];
        string last = strvec[vSize - 1];

        // get size of shortest string in the array
        int shortest = min(first.size() , last.size());

        // travel the shortest string to compare and find the prefix 
        for(int i = 0; i < shortest; i++)
        {
            if(first[i] != last[i])
            {
                return answer;
            }
            answer = answer + first[i];
        }
        return answer;

    }
};