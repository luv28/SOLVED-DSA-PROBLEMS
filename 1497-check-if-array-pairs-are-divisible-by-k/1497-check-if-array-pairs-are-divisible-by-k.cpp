class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            int key=((arr[i]%k)+k)%k;
            m[key]++;
        }
        for(auto a:m){
            if(a.first==0){
                if(a.second%2==0) continue;
                else return false;
            }
            if(m.find(k-a.first)==m.end() || m[k-a.first]!=a.second) return false;
        }
        return true;
    }
};