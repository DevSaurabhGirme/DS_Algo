// S.C = O(1001)    T.C = O(n)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();

        vector<int> freq(1001, 0);

        int SUM = 0;

        for(int &s : skill)
        {
            SUM += s;
            // updating frequency
            freq[s]++;
        }

        int noOfTeams = n/2;

        if(SUM % noOfTeams != 0)
            return -1;

        int targetSum = SUM / noOfTeams;
        long int chem = 0;

        for(int i = 0; i < n; i++)
        {
            int currSkill = skill[i];
            int other = targetSum - currSkill;

            // no counterpart found
            if(freq[other] <= 0)
                return -1;

            chem += (long int)currSkill * (long int)(other);
            freq[other]--;
        }

        return chem/2;
    }
};