class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();

        sort(skill.begin(), skill.end());

        int i = 0;
        int j = n-1;
        // skill of 1st team
        int sum = skill[i] + skill[j];

        // chemistry
        long int chem = 0;

        while(i < j)
        {
            int currSkillSum = skill[i] + skill[j];

            // skill sum doesn't match
            if(currSkillSum != sum)
                return -1;

            chem += (long int)(skill[i]) * (long int)(skill[j]);
        
            i++;
            j--;
        }

        return chem;
    }
};