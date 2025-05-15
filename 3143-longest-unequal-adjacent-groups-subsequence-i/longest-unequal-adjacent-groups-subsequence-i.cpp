class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // indices of words to take in final seq
        vector<int>w;
        for(int i = 0;i < words.size();i++){
            if(w.empty() || groups[i] != groups[w.back()]){
                w.push_back(i);
            }else{
                if(words[i].size() > words[w.back()].size()){
                    w.pop_back();
                    w.push_back(i);
                }
            }
        }
        vector<string>ans;
        for(auto &i:w){
            ans.push_back(words[i]);
        }
        return ans;
    }
};