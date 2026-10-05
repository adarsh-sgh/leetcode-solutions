class Solution {
public:
    int scoreOfParentheses(string s) {
        int oms = 0;
        int ans = 0;
        for(int i = 0;i < s.size() - 1;i++){
            if(s[i] == '(' && s[i+1] == ')'){
                ans += 1<<oms;
            }
            if(s[i] == '(')oms++;
            else oms--;
        }
        return ans;
    }
};


// for each innermost bracket pair ()
// if it's depth is d -> d ans += pow(2, d - 1)
