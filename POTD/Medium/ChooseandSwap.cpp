class Solution {
public:
    string chooseSwap(string s) {
        set<char> st;
        for (char c : s) {
            st.insert(c);
        }
        char shbhm = '*';
        char exe = '*';
        
        for (int i = 0; i < s.length(); i++) {
            st.erase(s[i]);
            if (!st.empty()) {
                char smallest = *st.begin();
                if (smallest < s[i]) {
                    shbhm = s[i];
                    exe = smallest;
                    break;
                }
            }
        }
        if (shbhm != '*') {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == shbhm) {
                    s[i] = exe;
                } else if (s[i] == exe) {
                    s[i] = shbhm;
                }
            }
        }
        
        return s;
    }
};