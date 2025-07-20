// Question 183.  Count Unique Vowel Strings

class Solution {
public:
    int vowelCount(string& s) {
        int n = s.length(), ans = 1;

        // Map to store frequency of each vowel
        unordered_map<char, int> m;

        // Step 1: Count the frequency of vowels in the string
        for (char x : s) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                m[x]++;
            }
        }

        // Step 2: If no vowels found, return 0
        if (m.size() == 0) return 0;

        // Step 3: Multiply ans by factorial of number of unique vowels (n!)
        // Example: 3 unique vowels → 3! = 3 * 2 * 1 = 6
        for (int i = 1; i <= m.size(); ++i)
            ans *= i;

        // Step 4: Multiply ans with frequency of each vowel
        // Example: a:3, e:1 → ans = ans * 3 * 1
        for (auto x : m)
            ans *= x.second;

        // Step 5: Return the final result
        return ans;
    }
};
