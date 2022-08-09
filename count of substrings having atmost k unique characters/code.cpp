#include<bits/stdc++.h>
using namespace std;

int helper(string &s,int &k){
    int acquire=0,release=0;
    int n=s.length();
    int distinct=0;
    int ans=0;
    unordered_map<char,int> m;
    for(acquire;acquire<n;acquire++){
        char currChar=s[acquire];
        if(m.find(currChar)!=m.end()) m[currChar]++;
        else{
            m[currChar]++;
            distinct++;
        }
        while(acquire>=release && distinct>k){
            char toRemove=s[release];
            m[toRemove]--;
            release++;
            if(m[toRemove]==0){
                m.erase(toRemove);
                distinct--;
            }
        }
        ans+=acquire-release+1;
    }
    return ans;
}

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    cout<<helper(s,k)<<endl;
}
