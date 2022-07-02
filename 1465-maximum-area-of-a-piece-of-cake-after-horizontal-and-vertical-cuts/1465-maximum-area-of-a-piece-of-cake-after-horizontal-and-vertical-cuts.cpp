class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& vert) {
        long int mod=1000000007;
        sort(hori.begin(),hori.end());
        sort(vert.begin(),vert.end());
        long int prehori=0,prevert=0,currhori=0,currvert=0;
        long int maxxh=INT_MIN,maxxw=INT_MIN;
        for(int i=0;i<hori.size();i++){
            currhori=i;
            maxxh=max(maxxh,hori[currhori]-prehori);
            prehori=hori[currhori];
        }
        currhori=h;
        maxxh=max(maxxh,currhori-prehori);
        maxxh=maxxh%mod;
        for(int i=0;i<vert.size();i++){
            currvert=i;
            maxxw=max(maxxw,vert[currvert]-prevert);
            prevert=vert[currvert];
        }
        currvert=w;
        maxxw=max(maxxw,currvert-prevert);
        maxxw=maxxw%mod;
        return (maxxh*maxxw)%mod;
    }
};