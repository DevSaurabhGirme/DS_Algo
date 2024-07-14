// T.C = O(n^2)

class Solution {
public:
    string countOfAtoms(string formula) 
    {
        int n = formula.length();

        stack<unordered_map<string, int>> map_stk;

        map_stk.push(unordered_map<string, int>());

        int i = 0;
        while(i < n)
        {
            if(formula[i] == '(')
            {
                map_stk.push(unordered_map<string, int>());
                i++;
            }
            else if(formula[i] == ')')
            {
                unordered_map<string, int> curr = map_stk.top();
                map_stk.pop();
                i++;
            
                string multi;
                while((i < n) && isdigit(formula[i]))
                {
                    multi.push_back(formula[i]);
                    i++;
                }

                // converting number in string to integer
                if(!multi.empty())
                {
                    int multiInt = stoi(multi);
                    for(auto &it : curr)
                    {
                        string element = it.first;
                        int count = it.second;

                        // calculating count of element
                        curr[element] = count*multiInt;
                    }
                }

                // merging to stack's top element
                for(auto &it : curr)
                {
                    string element = it.first;
                    int count = it.second;

                    map_stk.top()[element] += count;
                }
            }

            else
            {
                string currEl;
                currEl.push_back(formula[i]);
                i++;
            
                while(i < n && isalpha(formula[i]) && islower(formula[i]))
                {
                    currEl.push_back(formula[i]);
                    i++;
                }

                string currCnt;
                while(i < n && isdigit(formula[i]))
                {
                    currCnt.push_back(formula[i]);
                    i++;
                }

                // converting to integer
                int currCntInt = currCnt.empty() ? 1 : stoi(currCnt);
                map_stk.top()[currEl] += currCntInt;
            }
        }

        map<string, int> sortedMap(begin(map_stk.top()), end(map_stk.top()));

        string result;

        for(auto &it : sortedMap)
        {
            string element = it.first;
            result += element;
            int count = it.second;

            if(count > 1)
            {
                result += to_string(count);
            }
        }

        return result;

    }
};