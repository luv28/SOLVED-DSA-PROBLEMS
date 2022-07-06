class Solution {
public:
    int ans(int n,unordered_map<int,int> &m){
        if(n==0) return 0;
        if(n==1) return 1;
        int currkey=n;
        if(m.find(currkey)!=m.end()) return m[currkey];
        int a=ans(n-1,m);
        int b=ans(n-2,m);
        return m[currkey]=a+b;
    }
    int fib(int n) {
        unordered_map<int,int> m;
        return ans(n,m);
    }
};