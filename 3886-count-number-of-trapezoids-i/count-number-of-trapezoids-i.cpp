class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
    // y1 3 3c2  a 
    // y2 3 3c2 b 
    // y3 4 4c2 c

// b* a + c * (b + a)
// a b c
// b * a, c * (a + b)
map<int,int>mp;
for(auto &p:points){
    mp[p[1]]++;
}
long long sum = 0;
long long ans = 0;
int mod = 1e9 + 7;
for(auto &[_,f]:mp){
    long long fc2 = (1ll)*f * (f-1)/2;
     ans += sum * fc2;
     ans %= mod;
    sum += fc2;
    sum %= mod;
}
return ans;
}
};