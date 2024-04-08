class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n = students.size();

      /*int s_0 = 0;
        int s_1 = 0;    
      */

        int Arr[2] = {0};
        // Arr[0] = students prefering circular sandwich denoted by 0
        // Arr[1] = students prefering square sandwich denoted by 1
    
        for(int i = 0; i < n; i++)
        {
            // retrieve student preference
            int stud = students[i];
            // increment it
            Arr[stud]++;
        }

        for(int i = 0; i < n; i++)
        {
            int sand = sandwiches[i];

            // no student left with that particular prefered sandwich
            if(Arr[sand] == 0)
            {
                // return hungry students
                return n-i;
            }

            // students found their preference and left
            Arr[sand]--;
        }
        return 0;
    }
};