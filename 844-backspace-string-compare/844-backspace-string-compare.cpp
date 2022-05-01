class Solution {
public:
    string final(string s){
        string a="";
        int i=s.length();
        int c=0;
        while(c<i){
            if(s[c]=='#'){
                if(a.length()) a.pop_back();
                else a="";
            }
            else a+=s[c];
            c++;
            cout<<a<<endl;
        }
        return a;
    }

    bool backspaceCompare(string s, string t) {
        return final(s)==final(t);
    }
};