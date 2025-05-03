class Solution {
public:

    void backTrack(int i, vector<int>& score,vector<string>& words, int currScore, vector<int>& freq,int & maxScore)
    {
        maxScore = max(maxScore, currScore);

        int n = words.size();

        if(i >= n)
        {
            return;
        }

        // iterator to iterate over each word
        int j = 0;
        // calculating score of every word in words
        int tempScore = 0;

        // vector to store freq
        vector<int> tempFreq = freq;

        while(j < words[i].length())
        {
            char ch = words[i][j];

            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];

            if(tempFreq[ch - 'a'] < 0)
            {
                break;
            }
            j++;
        }

        if(j == words[i].length())
        {
            // take
            backTrack(i+1, score, words, currScore + tempScore, tempFreq,maxScore);
        }

        // dodn't take
        backTrack(i+1, score, words, currScore, freq, maxScore); // send original frequency
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        // keep track of available characters
        vector<int> freq(26, 0);

        // final score
        int maxScore = INT_MIN;

        for(char &ch : letters)
        {
            freq[ch - 'a']++;
        }

        int n = words.size();

        backTrack(0, score, words, 0, freq, maxScore);

        return maxScore;
        //lem;sldmv;
    }
};
