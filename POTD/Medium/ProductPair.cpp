//Question 780
class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> seen;
        
        for (int i = 0; i < arr.size(); i++) {
            long long current = arr[i];
            
            if (current == 0) {
                if (target == 0 && !seen.empty()) {
                    return true;
                }
            } 
            else if (target % current == 0) {
                long long required = target / current;
                if (seen.count(required)) {
                    return true;
                }
            }
            
            seen.insert(current);
        }
        
        return false;
    }
};