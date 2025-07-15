// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
      int n = arr.size();
      int fl = -1;
      int ce = INT_MAX;
      for(int i = 0; i<n; i++){
          if(arr[i] ==x){
              return {x,x};
          }else{
             if(arr[i] < x && fl <arr[i] ){
                  fl = arr[i];
              }
              if(arr[i]>x && ce > arr[i]){
                  ce = arr[i];
              }
          }

      }
      if(ce == INT_MAX){
          ce = -1;
      }
      return {fl,ce};
        
    }
};