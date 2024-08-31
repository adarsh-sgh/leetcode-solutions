class Solution {
public:
    // bitmask magic, see prev submissinos for recursion soln
    // 1-> open bracket, 0 -> closed bracket
    // least significant bit -> first char of seq 
    // 001011 => (()())
    bool isValid(int x, int n){
        int oc = 0, zc = 0;
        for(int i = 0;i<2 * n;i++){
            if(x >> i & 1)oc++;
            else zc++;
            if(zc > oc) return false;
        }
        return oc == n;
    }
    string str(int x,int n){
        string s;
        for(int i = 0;i<2*n;i++){
            if(x >> i & 1) s += '(';
            else s += ')';
        }
        return move(s);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        for(int i = 0;i<(1<<2*n);i++){
            if(isValid(i,n)){
                ans.push_back(str(i,n));
            }
        }     
        return ans;
    }
};