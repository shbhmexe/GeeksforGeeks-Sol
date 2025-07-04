#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str) {
        int arr[26] = {0};

        // Counting frequency
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            
            if (ch >= 'a' && ch <= 'z') {
                arr[ch - 'a']++;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                arr[ch - 'A']++;
            }
        }

        int maxi = -1;
        int ans = 0;

        // Finding maximum frequency
        for (int i = 0; i < 26; i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
                ans = i;
            }
        }

        return 'a' + ans;
    }
};

int main() {
    Solution obj;
    string str = "testsampleString";

    cout << "Maximum occurring character: " << obj.getMaxOccuringChar(str) << endl;

    return 0;
}



// class Solution
// {
//     public:
//     //Function to find the maximum occurring character in a string.
//     char getMaxOccuringChar(string str)
//     {
//         // Your code here
//         int arr[26] = {0};
//         for (int i=0; i<str.length(); i++) {
//             int ch = str[i] - 'a';      // this will convert char to num like a=0, b=1, z=25, etc
//             arr[ch]++;
//         }
        
//         int maxi = -1;
//         int ans = 0;
        
//         for (int i=0; i<26; i++) {
//             if (maxi < arr[i]) {
//                 maxi = arr[i];
//                 ans = i;
//             }
//         }
//         return 'a' + ans;
//     }

// };