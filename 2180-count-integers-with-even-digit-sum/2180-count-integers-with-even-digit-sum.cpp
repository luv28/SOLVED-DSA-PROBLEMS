class Solution {
public:
    int countEven(int num) {
        int sum=0;
        int temp=num;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }
        return sum%2==0?num/2:(num-1)/2;
    }
};