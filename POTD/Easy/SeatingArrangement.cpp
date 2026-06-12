//Questipn 18 june 26

class Solution {
public:
    bool canSeatAllPeople(int k, vector<int>& seats) {
        int n = seats.size();
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (i < n - 1 && seats[i + 1] == 1) {
                    return false;
                }
            } else {
                bool leftSafe = (i == 0 || seats[i - 1] == 0);
                bool rightSafe = (i == n - 1 || seats[i + 1] == 0);
                
                if (leftSafe && rightSafe) {
                    seats[i] = 1;
                    k--;
                }
            }
        }
        
        return k <= 0;
    }
};