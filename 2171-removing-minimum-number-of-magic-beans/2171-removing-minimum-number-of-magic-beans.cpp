class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long n=beans.size(),backCount=0; //no. of elements before i 
        long long sum=0;
        long long minBeans=LLONG_MAX;
        for(auto bean:beans) sum+=bean;
        for(int i=0;i<n;i++){
            if(i!=0 && beans[i]==beans[i-1]){
                backCount++;
                continue;
            }
            if(minBeans>sum-(n-backCount)*beans[i]) minBeans=sum-(n-backCount)*beans[i];
            backCount++;
        }
        return minBeans;
    }
};