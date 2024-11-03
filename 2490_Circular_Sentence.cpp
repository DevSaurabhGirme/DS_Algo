class Solution {
public:
    bool isCircularSentence(string sent) 
    {
        int n = sent.length();

        // if first character is not equal to last character of the sentence
        if(sent[0] != sent[n-1])
        {
            return false;
        }

        for(int i = 1; i < n; i++)
        {   
            // one word iterated
            if(sent[i] == ' ')
            {
                // last character of current word doesn't match first character of next word
                if(sent[i-1] != sent[i+1])
                    return false;
            }
        }

        return true;
    }
};