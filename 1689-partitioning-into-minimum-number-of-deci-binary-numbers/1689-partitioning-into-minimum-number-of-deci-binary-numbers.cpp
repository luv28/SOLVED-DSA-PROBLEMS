class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(char a:n){
            ans=max(ans,a-'0');
        }
        return ans;
    }
};