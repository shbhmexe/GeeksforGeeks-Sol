//Question 243
class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        int c = 0, e = s.size() - 1;

        while (c < e) {
            // Skip non-alphanumeric characters from the start
            if (!isalnum(s[c])) {
                c++;
            }
            // Skip non-alphanumeric characters from the end
            else if (!isalnum(s[e])) {
                e--;
            }
            // Compare characters ignoring case
            else if (tolower(s[c]) != tolower(s[e])) {
                return false;
            }
            else {
                c++;
                e--;
            }
        }
        return true;
    }
};
