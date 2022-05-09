class Solution {
public:
    vector<string> m={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},ans;
    void helper(string &digits,int ci,string s){  //for backtracking use string &digits
        if(ci==digits.length()){
            ans.push_back(s);
            return;
        }                                                                  //for backtracking
        for(auto a:m[digits[ci]-'2']) helper(digits,ci+1,s+a);       //s.push_back(a); helper(digits,ci+1,s);
    }                                                                   //s.pop_back();
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return ans;
        helper(digits,0,"");
        return ans;
    }
    
};

