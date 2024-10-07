// T.C = O(m+n)     S.C = O(m+n)

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) 
    {
        if(s1.length() < s2.length())
            swap(s1, s2);
    
        vector<string> s1_vec;
        vector<string> s2_vec;

        stringstream ss1(s1);
        string token;
        // retrieve each word from ss1
        while(ss1 >> token)
        {
            s1_vec.push_back(token);
        }
    
        stringstream ss2(s2);

        // retrieve each word from ss2
        while(ss2 >> token)
        {
            s2_vec.push_back(token);
        }

        int i = 0;
        int j = s1_vec.size()-1;

        int k = 0;
        int l = s2_vec.size()-1;

        while(k < s2_vec.size() && i < s1_vec.size() && s2_vec[k] == s1_vec[i])
        {
            k++;
            i++;
        }

        while(l >= k && s2_vec[l] == s1_vec[j])
        {
            j--;
            l--;
        }

        if(l < k)
            return true;
  
        return false;

    }
};