class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string>v;
       for(auto &x:nums){
        v.push_back(to_string(x));
       } 
       sort(v.begin(),v.end(),[&](auto &x, auto &y){
            string n1 = x + y, n2 = y + x;
            // number bada => ya to length badi (without leading zero) (len is same here)
            // ya fir first no. jispar differ karte wo bada 
            for(int i = 0;i<n1.size();i++){
                if(n1[i] == n2[i]) continue;
                return n1[i]  > n2[i];
            }
            return false;
            // return stoll(x + y) > stoll(y + x);
       });

       string ans;
       if(v[0] == "0") return "0";
       for(auto &x:v){
        ans+= x;
       }
       // trim leading zeroes
       return ans;
    }
};