class Solution {
public:
    int sod(int x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x/=10;
        }
        return sum;
    }
     int countLargestGroup(int n) {
       map<int,int>mp;
       int mx_val = 0;
       for(int i = 1;i <= n;i++){
        mp[sod(i)]++;
        mx_val = max(mx_val, mp[sod(i)]);
       } 
       int ans = 0;
       for(auto &[k,v]:mp){
        ans += v == mx_val;
       }
       return ans;
    }
};