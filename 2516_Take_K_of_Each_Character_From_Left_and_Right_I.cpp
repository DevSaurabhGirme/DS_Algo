// TC = O(2^n)    S.C = O(1)

class Solution {
public:
    void Recur(string s, int k, int i, int j, int minutes, vector<int>& freq, int& answer)
    {   
        //      a               b               c 
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k)
        {
            answer = min(answer, minutes);
            return;
        }

        // checked all characters of the window
        if(i > j)
            return;

        // including leftmost character
        vector<int> leftFreq = freq;
        leftFreq[s[i] - 'a'] += 1;
        Recur(s, k, i+1, j, minutes+1, leftFreq, answer);
    
        // including rightmost
        vector<int> rightFreq = freq;
        rightFreq[s[j] - 'a'] += 1;
        Recur(s, k, i, j-1, minutes+1, rightFreq, answer);
    }

    int takeCharacters(string s, int k) 
    {
        // to store fequency of a, b and c
        vector<int> freq(3,0);

        int i = 0;
        int j = s.length()-1;
        int minutes = 0;
        int answer = INT_MAX;

        Recur(s, k, i, j, minutes, freq, answer);
        
        if(answer == INT_MAX)
        {
            return -1;
        }

        return answer;
    }
};