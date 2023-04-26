class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>m1,m2;
        for(auto &&c:word1)m1[c]++;

        for(auto &&c:word2) m2[c]++;
        vector<int>v1,v2;
        for(auto &&x:m1) {
            if(!m2[x.first]) return false;
            v1.push_back(x.second);
            }
        for(auto &&x:m2) {
            if(!m1[x.first]) return false;
            v2.push_back(x.second);
            }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1 == v2;
    }
};