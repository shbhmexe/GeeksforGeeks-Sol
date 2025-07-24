//Quesrtion 233

// User function Template for C++
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int distinct(vector<vector<int>> M, int N) {
        int rows = M.size();
        int cols = M[0].size();
    
        unordered_set<int> common(M[0].begin(), M[0].end());
    
        for (int i = 1; i < rows; ++i) {
            unordered_set<int> rowSet(M[i].begin(), M[i].end());
            unordered_set<int> temp;
    
            for (int num : common) {
                if (rowSet.count(num)) {
                    temp.insert(num);
                }
            }
            common = std::move(temp);
        }

        // Return count of common elements
        return common.size();
    }
};
