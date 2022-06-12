class Solution {
    unordered_map<long long,long long> m;
public:
    int helper(int n){
        if(n<=2) return n;
        if(m.find(n)!=m.end()) return m[n];
        return m[n]=1+min(n%2+helper(n/2),n%3+helper(n/3));
    }
    int minDays(int n) {
        return helper(n);
    }
};