//Question 224
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // If lengths are not equal, they can't be rotations
        if (s1.length() != s2.length()) 
            return false;

        // Concatenate s1 with itself and see if s2 is a substring
        string temp = s1 + s1;

        // If s2 is a substring of temp, then s1 and s2 are rotations
        return (temp.find(s2) != string::npos);
    }
};
