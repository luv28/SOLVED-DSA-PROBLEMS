class Solution {
public:
    bool isOpen(char s){
        return s=='(' || s=='[' || s=='{';
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(auto a:s){
            if(isOpen(a)) st.push(a);
            else{
                if(st.empty() || (st.top()=='(' && a!=')') || (st.top()=='[' && a!=']') || (st.top()=='{' && a!='}')) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};