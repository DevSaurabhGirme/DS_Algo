// using STL library functions

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        // finding index of first charatcer appearance from last of the string
        int idx = s.find_last_not_of(' ')+ 1;

        // erasing trailing spaces
        s.erase(idx);

        // finding first space in the modified string
        int last_space_index = s.find_last_of(' ');

        // no spaces found hence the given string is thelast word itself 
        if(last_space_index == string::npos)
        {
            // return length of that string
            return s.length();
        }
        else
        {
            // length of last word
            return s.length() - last_space_index - 1;
        }
        
    }
};