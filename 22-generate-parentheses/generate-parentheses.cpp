class Solution {
public:
    vector<string>ans;
    void fill(const string &s, int o, int c, int n){
        if(s.size() == 2 * n){
            if(o != c) return;
            ans.push_back(s);
        } 
        if(o < n){
            fill(s + '(', o + 1, c, n);
        }
        if(c < o){
            fill(s + ')', o, c + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        fill("(", 1,0,n);
        return ans;
    }
};