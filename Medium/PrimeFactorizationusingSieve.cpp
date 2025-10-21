//Question 507
class Solution {
  public:
    int nG;
    vector<int> ansG;
    vector<bool> primeG;
  
    // void sieve(int n, vector<bool> &prime, vector<int> &ans){
    //     for(int i=2;i<=n;i++){
    //         if(prime[i]){
    //             while(n>=i && n%i==0){
    //                 n/=i;
    //                 ans.push_back(i);
    //             }
    //             for(int j=i+i;j<=n;j+=i)
    //               prime[j] = false;
                
    //         }
    //     }
    //     return;
    // }
    
    void sieve(){
        for(int i=2;i<=nG;i++){
            if(primeG[i]){
                while(nG>=i && nG%i==0){
                    nG/=i;
                    ansG.push_back(i);
                }
                for(int j=i+i;j<=nG;j+=i)
                  primeG[j] = false;
                
            }
        }
        return;
    }

    vector<int> findPrimeFactors(int N){
        vector<bool> prime(N+1, true);
        prime[1] = false;
        primeG = prime;
        nG = N;
        sieve();
        return ansG;
    }
};