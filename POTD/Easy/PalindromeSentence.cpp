//Question 331
class Solution {
  public:
    bool isPalinSent(string &s) {
        // Two pointers approach: i from start, j from end
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // Skip non-alphanumeric characters from the start
            if (!isalnum(s[i])) {
                i++;
            }
            // Skip non-alphanumeric characters from the end
            else if (!isalnum(s[j])) {
                j--;
            }
            // Compare lowercase versions of characters
            else if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            }
            // If characters don't match, it's not a palindrome
            else {
                return false;
            }
        }

        // If loop completes, it's a valid palindrome
        return true;
    }
};
