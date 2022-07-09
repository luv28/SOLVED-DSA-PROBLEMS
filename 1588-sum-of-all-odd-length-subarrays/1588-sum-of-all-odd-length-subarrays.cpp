class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix;
        prefix.push_back(0);
        int n=arr.size();
        for(int i=0;i<n;i++) prefix.push_back(prefix[i]+arr[i]);
        int ans=0;
        for(int i=0;i<prefix.size();i++){
            for(int j=i+1;j<prefix.size();j+=2){
                if(j<prefix.size()) ans+=prefix[j]-prefix[i];
            }
        }
        return ans;
    }
};