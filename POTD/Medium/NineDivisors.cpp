class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int ans=0;
        for(int i=2;i*i<=n;i++){
            int c=0;
            int t=i,r=2;
            int f=0;
            int r2=-1;
            while(t!=1){
                if(t%r==0){
                    t/=r;
                    if(r2==r)f++;
                    c++;
                    r2=r;
                }
                else{
                    r++;
                }
            }
            if((f==0 && c==2) || (f==3 && c==4)){
                ans++;
            }
        }
        return ans;
    }
};