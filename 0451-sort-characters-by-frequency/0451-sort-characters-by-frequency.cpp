class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto &&c:s){
            m[c]++;
        }
        vector<pair<int,char>>v;
        for(auto &&x:m){
           v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),[&](auto &x,auto &y){
            if(x.first != y.first) return x.first > y.first;
           return x.second < y.second;
        });
        string ans = "";
        for(auto &&x:v){
            while(x.first--){
                ans += x.second;
            }
        }
        return ans;
    }
};