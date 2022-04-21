class Solution {
public:
    int getLucky(string s, int k) {
        string a="";
        int sum=0;
        for(auto c:s){
            int val=c-'a'+1;
            sum+=(val%10)+(val/10);
        }
        while(k-1){
            int b=sum;
            sum=0;
            while(b){
                sum+=b%10;
                b=b/10;
            }
            k--;
        }
        return sum;
    }
};