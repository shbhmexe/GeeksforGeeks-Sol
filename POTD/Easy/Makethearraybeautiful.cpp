//Question 777
class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> shbhm;
        
        for(int exe = 0; exe < arr.size(); exe++) {
            if(shbhm.empty()) {
                shbhm.push_back(arr[exe]);
            } 
            else if((shbhm.back() >= 0 && arr[exe] < 0) || (shbhm.back() < 0 && arr[exe] >= 0)) {
                shbhm.pop_back();
            } 
            else {
                shbhm.push_back(arr[exe]);
            }
        }
        
        return shbhm;
    }
};