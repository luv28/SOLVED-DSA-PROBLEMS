class Solution {
public:
    int solve(int num){
        int sum=0,c=0;
        while(num){
            sum+=num%10;
            num/=10;
            c++;
        }
        if(c==1||c==0) return sum;
        else return solve(sum);
        
    }
    int addDigits(int num) {
        return solve(num);
    }
};