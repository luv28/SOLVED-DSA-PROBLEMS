class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> v(numRows,"");
        int count=0;
        int limit=s.length()-1;
        while(count<=limit){
            for(int i=0;i<numRows-1;i++){
                if(count>limit) break;
                if(i>=0) v[i].push_back(s[count++]);
            }            
            for(int i=numRows-1;i>=1;i--){
                if(count>limit) break;
                if(i>=0) v[i].push_back(s[count++]);
            }
        }
        string ans;
        for(int i=0;i<numRows;i++) ans+=v[i];
        return ans;
    }
};

