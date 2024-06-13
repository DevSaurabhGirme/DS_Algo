// T.C = O(n)

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        int n = seats.size();

        vector<int> seat_position(101, 0);
        vector<int> stud_position(101, 0);

        for(int &position : seats)
        {
            // incrementing frequency of seats
            seat_position[position]++;
        }

        for(int &position : students)
        {
            // incrementing frequency of students
            stud_position[position]++;
        }

        int i = 0;
        int j = 0;
        int moves = 0;

        while (n > 0) // (i <= 100 && j <= 100)
        {
            if(seat_position[i] == 0){
                i++;
            }
            if(stud_position[j] == 0){
                j++;
            }

            if(seat_position[i] != 0 && stud_position[j] != 0){
                moves = moves + abs(j-i);

                seat_position[i]--;
                stud_position[j]--;

                n--;
            }
        }
        

        return moves;
    }
};
