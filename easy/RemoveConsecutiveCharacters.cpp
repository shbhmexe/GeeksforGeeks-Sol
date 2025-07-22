//Question 208
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        stack<char> st;

        for (char ch : s) {
            // If stack is empty or top is not equal to current character, push it
            if (st.empty() || st.top() != ch) {
                st.push(ch);
            }
            // Else, it's a consecutive duplicate, so skip it
        }

        string result = "";

        // Pop characters to form the final string
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // The characters were added in reverse order, so reverse the result
        reverse(result.begin(), result.end());

        return result;
    }
};
