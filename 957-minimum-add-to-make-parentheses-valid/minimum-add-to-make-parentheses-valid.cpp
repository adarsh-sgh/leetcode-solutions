class Solution {
public:
    int minAddToMakeValid(string s) {
       int ans = 0;
       int oms = 0;
       for(auto &c:s) {
        if(c == '('){
            oms++;
        }else{
            if(oms){
                oms--;
            }else{
                ans++;
            }
        }
       }
       ans += oms;
       return ans;
    }
};


// if oms < 0 make it zero ans++
// in the end add oms to ans