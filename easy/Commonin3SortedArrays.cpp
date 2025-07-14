    class Solution {
      public:
        vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                                   vector<int> &arr3) {
              vector<int> v;
              vector<int> w;
              int a = arr1.size();
              int b = arr2.size();
              int c = arr3.size();
              for(int i = 0;i<a;i++){
                  if(i > 0 && arr1[i] == arr1[i - 1]){
                      continue;
                  }
                  int target1 = arr1[i];
                  int s1 = 0;
                  int e1 = b-1;
                  int x1 = INT_MIN;
                  while(s1<=e1){
                      int mid1 = s1+(e1-s1)/2;
                      if(arr2[mid1] == target1){
                          s1 = mid1 + 1;
                          x1 = target1;
                          break;
                      }
                      else if(arr2[mid1]>target1){
                          e1 = mid1 -1;
                      }
                      else{
                          s1 = mid1 + 1;
                      }
                  }
                  if(x1 > INT_MIN){
                  int s2 = 0;
                  int e2 = c-1;
                  int x2 = INT_MIN;
                  while(s2<=e2){
                      int mid2 = s2+(e2-s2)/2;
                      if(arr3[mid2] == target1){
                          s2 = mid2 + 1;
                          x2 = target1;
                          break;
                      }
                      else if(arr3[mid2]>target1){
                          e2 = mid2 -1;
                      }
                      else{
                          s2 = mid2 + 1;
                      }
                  }
                  if(x2 > INT_MIN){
                      v.push_back(arr1[i]);
                  }
                  }
              }
             sort(v.begin(),v.end());
             int size = v.size();
             if(size == 0){
                 return {-1};
             }
              int kcount = 0;
           for(int k = 0;k<size;k++){
                if(v[k] < 0){
                    kcount++;
                }
            }  
            if(kcount == 0){
                int count[100001] = {0};
                for(int i = 0;i<v.size();i++){
                    count[v[i]]++;
                    if(count[v[i]] == 1){
                        w.push_back(v[i]);
                    }
                    else if(count[v[i]] > 1){
                        continue;
                    }
                }
            }
            else if(kcount > 0){
                if(kcount == size){
                 for(int i = 0;i<size;i++){
                    v[i] = -v[i];
                }
                int count3[100001] = {0};
                for(int i = 0;i<size;i++){
                    count3[v[i]]++;
                    if(count3[v[i]] == 1){
                        w.push_back(-v[i]);
                    }
                    else{
                        continue;
                    }
                }
                }
                else{
                int p = -1;
                for(int i = 0;i<size;i++){
                    if(v[i] >= 0){
                      p = i;
                      break;
                    }
                }
                for(int i = 0;i<p;i++){
                    v[i] = -v[i];
                }
                int count1[100001] = {0};
                for(int i = 0;i<p;i++){
                    count1[v[i]]++;
                    if(count1[v[i]] == 1){
                        w.push_back(-v[i]);
                    }
                    else{
                        continue;
                    }
                }
                int count2[100001] = {0};
                for(int i = p;i<v.size();i++){
                     count2[v[i]]++;
                    if(count2[v[i]] == 1){
                        w.push_back(v[i]);
                    }
                    else{
                        continue;
                    }
                }
            }
            }
           sort(w.begin(),w.end());
           return w; 
        }
    };