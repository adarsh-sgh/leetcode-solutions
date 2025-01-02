class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>v;
        set<char> vo = {'a', 'e','i','o','u'};
        for(int i =0;i < words.size();i++){
            if(vo.count(words[i][0]) && vo.count(words[i].back())){
               v.push_back(i);
            }
        }
        for(auto &q:queries){
            int x = q[0], y = q[1];
            // element bw x and y inclusive
            auto lb = lower_bound(v.begin(),v.end(), x);
            auto ub = upper_bound(v.begin(), v.end(), y);
            ans.push_back(ub - lb); 
        }
        return ans;
    }
};