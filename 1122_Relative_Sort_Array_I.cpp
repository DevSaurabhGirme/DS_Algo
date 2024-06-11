class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        // ordered_map
        map<int, int> ordmap;    
    
        for(int &num : arr1)
        {
            ordmap[num]++;
        }

        int i = 0;
        for(int &num : arr2)
        {
            // modifying arr1
            while(ordmap[num]-- > 0)
            {
                arr1[i++] = num;
            }
        }

        // adding the remaining elements
        for(auto &it : ordmap)
        {
            int freq = it.second;

            while(freq > 0)
            {
                arr1[i++] = it.first;
                freq--;
            }
        }
        return arr1;

    }
};