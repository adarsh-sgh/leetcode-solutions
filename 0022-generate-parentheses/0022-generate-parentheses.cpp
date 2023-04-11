class Solution {
public:
    void putParenthesis(const int n,int o,int c,string &s,vector<string>&ans){
        if(o == n && c == n){
            ans.push_back(s);
            return;
        }
        if(o < n){
            s.push_back('(');
            putParenthesis(n,o+1,c,s,ans);
            s.pop_back();
        }
        if(c < o){
            s.push_back(')');
            putParenthesis(n,o,c+1,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        putParenthesis(n,0,0,s,ans);
        return ans;
    }
};