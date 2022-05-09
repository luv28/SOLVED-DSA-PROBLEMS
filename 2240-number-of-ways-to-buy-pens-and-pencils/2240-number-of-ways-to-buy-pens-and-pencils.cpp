class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int pen_count=total/cost1;
        long long sum=0;
        for(int i=0;i<=pen_count;i++){
            int pencil_count=(total-(i*cost1))/cost2;
            sum+=pencil_count+1;
        }
        
        return sum;
    }
};