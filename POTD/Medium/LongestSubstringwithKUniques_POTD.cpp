#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        vector<int> freq(26, 0);
        int unique = 0;
        int maxi = -1;
        
        int i = 0;
        
        for (int j = 0; j < s.size(); j++) {
            freq[s[j] - 'a']++;
            
            if (freq[s[j] - 'a'] == 1) {
                unique++;
            }
            
            while (unique > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) {
                    unique--;
                }
                i++;
            }
            
            if (unique == k) {
                maxi = max(maxi, j - i + 1);
            }
        }
        
        return maxi;
    }
};

int main() {
    Solution obj;
    string s = "aabacbebebe";
    int k = 3;
    
    cout << "Longest Substring Length with " << k << " unique characters: " 
         << obj.longestKSubstr(s, k) << endl;
         
    return 0;
}


// \class Solution {
// public:
//     int longestKSubstr(string &s, int k) {
//         vector<int> freq(26, 0);
//         int unique = 0;
//         int maxi = -1;
        
//         int i = 0;
        
//         for (int j = 0; j < s.size(); j++) {
//             freq[s[j] - 'a']++;
            
//             if (freq[s[j] - 'a'] == 1) {
//                 unique++;
//             }
            
//             while (unique > k) {
//                 freq[s[i] - 'a']--;
//                 if (freq[s[i] - 'a'] == 0) {
//                     unique--;
//                 }
//                 i++;
//             }
            
//             if (unique == k) {
//                 maxi = max(maxi, j - i + 1);
//             }
//         }
        
//         return maxi;
//     }
// };