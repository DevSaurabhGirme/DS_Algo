class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int i = 0;
        int j = word.find(ch);

        while(i < j)
        {
            char temp = word[i];
            word[i] = word[j];
            word[j] = temp;
        
            i++;
            j--;
        }

        return word;

    }
};