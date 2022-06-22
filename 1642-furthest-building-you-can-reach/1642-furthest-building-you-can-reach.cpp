class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0,n=heights.size();
        for(i;i<n-1;i++){
            int jump=heights[i+1]-heights[i];
            if(jump<=0) continue;
            else{
                bricks-=jump;
                pq.push(jump);
                if(bricks<0){
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                }
                if(ladders<0) break;
            }            
        }
        return i;
    }
};
	
