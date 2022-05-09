class Solution {
public:
    vector<string> m={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},ans;
    void helper(string &digits,int ci,string s){
        if(ci==digits.length()){
            ans.push_back(s);
            return;
        }
        for(auto a:m[digits[ci]-'2']) helper(digits,ci+1,s+a);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return ans;
        helper(digits,0,"");
        return ans;
    }
    
};

// vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
// vector<string> letterCombinations(string digits) {
// 	if(digits == "") return ans;         
// 	helper(digits, 0, "");              
// 	return ans;
// }

// void helper(string &digits, int i, string s){	
// 	if(i == digits.length()) ans.push_back(s);    
// 	else 
// 		for(auto c : mappings[digits[i] - '2']) helper(digits, i + 1, s+c);
// }