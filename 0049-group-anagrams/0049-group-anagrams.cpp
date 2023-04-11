class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        for(auto &&x:strs){
            // bitset<26> bs;
            // unsigned int bs = 0;
            vector<int> key(26);
            for(auto &&c:x){
                int i = c - 'a';
                // bs.set(i);
                // bs |= (1<<i);
                key[i]++;
            }
            mp[key].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto &&x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};