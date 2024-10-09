class Solution {
public:
    int minAddToMakeValid(string s) {
       int o = 0;
       int ans = 0;
       for(auto &c:s){
        if(c=='('){
            o++;
        }else if(o == 0){
            ans++;
        }else{
            o--;
        }
       } 
       return ans + o;
    }
};