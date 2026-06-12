//Question 14 june 26
class Solution {
public:
    string profession(int level, int pos) {
        int shbhm = 0;
        int exe = pos;
        
        while (exe > 1) {
            if (exe % 2 == 0) {
                shbhm++;
            }
            exe = (exe + 1) / 2;
        }
        
        if (shbhm % 2 == 0) {
            return "Engineer";
        } else {
            return "Doctor";
        }
    }
};