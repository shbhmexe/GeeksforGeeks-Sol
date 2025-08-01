class Solution {
  public:

    void rearrange(vector<int> &arr) {
        //CodeGenius
        vector<int> neg,pos,ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        int i=0,j=0;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
            
            ans.push_back(neg[j++]);
            
        }
        while(i<pos.size()){
            ans.push_back(pos[i++]);
        }
        while(j<neg.size()){
            ans.push_back(neg[j++]);
        }
        arr=ans;
    }
};