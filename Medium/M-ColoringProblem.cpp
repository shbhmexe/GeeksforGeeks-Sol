//Question 393
class Solution {
  public:
  bool check(vector<vector<int>>&graph,int src,int curr,vector<int>&color){
      for(auto x:graph[src]){
          if(color[x]==curr)return false;
      }
      return true;
  }
  bool ans=false;
   void dfs(int v,vector<vector<int>>&graph,int m,vector<int>&color,int src){
        if(ans==true)return;//no more checking to avoid TLE
       if(src==v){
           ans=true;
           return;
       }
       for(int i=1;i<=m;i++){
           if(check(graph,src,i,color)){
                color[src]=i;
                dfs(v,graph,m,color,src+1);
                color[src]=0;
           }
       }
   }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>>graph(v);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int>color(v,0);
        dfs(v,graph,m,color,0);
        return ans;
    }
};

