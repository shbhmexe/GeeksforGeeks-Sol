
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // CodeGenius
        int i=a.size()-1, j=0;
        while(i>=0 && j<b.size()){
            if(a[i]<b[j]) break;
            else{
                swap(a[i--],b[j++]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return ;
    }
};
