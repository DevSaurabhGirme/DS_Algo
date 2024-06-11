class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        // ordered_map
        map<int, int> ordmap;    
    
        // storing number and its index
        for(int i = 0; i < arr2.size(); i++)
        {
            ordmap[arr2[i]] = i;
        }

        for(int &num : arr1)
        {
            if(!ordmap.count(num))
            {
                ordmap[num] = 1e9;
            }
        }

        auto lambda = [&](int &num1,  int &num2)
        {
            // 1e9 case
            if(ordmap[num1] == ordmap[num2])
            {
                return num1 < num2;
            }
            // return number with smaller index
            return ordmap[num1] < ordmap[num2];
        };

        // sorting arr1 according to arr2 as mentioned in lambda
        sort(begin(arr1), end(arr1), lambda);

        return arr1;

    }
};