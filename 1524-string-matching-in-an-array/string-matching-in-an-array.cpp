class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
       set<string>se(words.begin(), words.end());
       set<string>ans;
       for(auto &w:words){
        for(int i = 0;i<w.size();i++){
            for(int j = i;j<w.size();j++){
                if(i == 0 && j == w.size() - 1) continue;
                string sub = w.substr(i, j - i + 1);
                if(se.count(sub)){
                    ans.insert(sub);
                };
            }
        }
       } 
       return vector<string>(ans.begin(), ans.end());
    }
};