class Solution {
public:
    int numTilings(int n) {
        vector<long long int> f(n+4,0);
        vector<long long int> g(n+4,0);
        f[0]=g[0]=0;
        f[1]=g[1]=1;
        f[2]=g[2]=2;
        for(int i=3;i<=n;i++){
            f[i]=(f[i-1] + f[i-2] + 2*g[i-2])%1000000007;
            g[i]=(g[i-1]+f[i-1])%1000000007;
        }
        return f[n];
    }
};
        
