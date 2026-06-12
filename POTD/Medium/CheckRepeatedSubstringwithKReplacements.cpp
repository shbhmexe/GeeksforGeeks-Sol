//Question 21 june26
class Solution {
  public:
    bool kSubstr(string &s, int k) {
        if(s.size() % k != 0){
            return false;
        }
        unordered_map<string, int> freqMap;
        
        for(int i = 0; i < s.size(); i+= k){      
            string sub = s.substr(i, k);
            freqMap[sub]++;
        }
        
            if (freqMap.size() == 1) {
                return true;
            }   
            if (freqMap.size() > 2) {
                return false;
            }
        for (auto it : freqMap) {
            if (it.second == 1) {
                return true;
            }
        }
        return false;
    }
};