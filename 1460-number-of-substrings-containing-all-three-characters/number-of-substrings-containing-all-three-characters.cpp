class Solution {
public:
    int numberOfSubstrings(string s) {
       // i -> last a
       // j -> last b
       // k -> last c
       //x = min(i,j,k) -> current is the smallest good substr ending here 
       // ans += x + 1

       // i, j, k
        vector<int>v(3,-1);
        int ans = 0;
       for(int i = 0;i< s.size();i++){
         v[s[i] - 'a'] = i;
         int x = min({v[0], v[1], v[2]});
         if(x >= 0){
            ans += x + 1;
         }
       }
       return ans;
    }
};