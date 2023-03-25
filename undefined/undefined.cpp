class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        set<char> v = {'a','e','i','o','u'};
        for(int i = left;i<=right;i++){
            if(v.count(words[i][0]) && v.count(words[i].back())){
                cnt ++;
            }
        }
        return cnt;
    }
};