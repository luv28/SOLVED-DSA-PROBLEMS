class Solution {
public:
    int convertTime(string current, string correct) {
        int cuh=stoi(current.substr(0,2));        
        int cum=stoi(current.substr(3,2));
        int coh=stoi(correct.substr(0,2));
        int com=stoi(correct.substr(3,2));
        int target=(com-cum)+60*(coh-cuh);
        int ans=0;
        vector<int> arr={60,15,5,1};
        for(auto a:arr){
            if(target>=a){
                ans+=target/a;
                target=target%a;
            }
        }
        return ans;
    }
};