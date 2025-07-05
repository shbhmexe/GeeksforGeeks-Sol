// First Solution: The Celebrity Problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& mat, int a, int b, int n) {
        return mat[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& mat, int n) {
        stack<int> s;

        // Step 1: Push all people into stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Find potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(mat, a, b, n)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int ans = s.top();

        // Step 3: Verify candidate

        // Row check (should be all 0)
        for (int i = 0; i < n; i++) {
            if (mat[ans][i] != 0)
                return -1;
        }

        // Column check (should be all 1 except diagonal)
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][ans] == 1)
                oneCount++;
        }

        if (oneCount != n - 1)
            return -1;

        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int n = mat.size();
    int celeb = obj.celebrity(mat, n);

    if (celeb == -1)
        cout << "No Celebrity found\n";
    else
        cout << "Celebrity is person at index: " << celeb << endl;

    return 0;
}


// 2nd Solution: The Celebrity Problem

// class Solution {
//   public:
//     // Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& mat) {
       
//         int n=mat.size();
//         int a=0;
//         int b=n-1;
//         while(a<b){
//             if(mat[a][b])
//             a++;
//             else
//             b--;
//         }
//         for(int i=0;i<n;i++){
//             if((i!=a) && (mat[a][i] || !mat[i][a]))
//             return -1;
//         }
//         return a;
//     }
// };