class Solution {
public:
    bool solve(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        if(sum==1) return true;
        else if(sum==89) return false;
        else return solve(sum);
    }
    bool isHappy(int n) {
        return solve(n);
    }
};