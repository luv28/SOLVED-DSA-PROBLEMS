class Solution {
public:
    bool isUgly(int n) {
        vector<int> primes={2,3,5};
        if(n<1) return false;
        for(auto p :primes) while(n%p==0) n=n/p;
        return n==1;
    }
};