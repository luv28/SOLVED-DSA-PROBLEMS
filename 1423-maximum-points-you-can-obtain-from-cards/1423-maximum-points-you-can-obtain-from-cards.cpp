class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++) sum+=cardPoints[i];
        int maxx=sum;
        int i=k-1,j=cardPoints.size()-1;
        while(i+1){
            sum=sum+cardPoints[j--]-cardPoints[i--];
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};