// T.C - O(n logn)      S.C = O(n)

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        // ector to store integers as string
        vector<string> arr;

        for(int &num : nums) 
        {
            arr.push_back(to_string(num));
        }
        
        auto customComp = [] (string &s1, string &s2)
        {
            if(s1+s2 > s2+s1)
            {
                return true;
            }
            return false;
        };

        // sorting the string array using custom comparator
        sort(begin(arr), end(arr), customComp);

        if(arr[0] == "0")
        {
            return "0";
        }

        string result;

        for(string &s : arr)
        {
            result += s;
        }
        
        return result;
    }
};