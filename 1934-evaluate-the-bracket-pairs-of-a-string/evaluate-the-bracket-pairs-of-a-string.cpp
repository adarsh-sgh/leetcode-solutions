class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(auto &x:knowledge){
            mp[x[0]] = x[1];
        } 

        string curr_key = "";
        bool inside_bracket = false;
        string ans = "";
        for(auto &c:s){
            if(c == '(') inside_bracket = true;
            else if(c == ')'){
                inside_bracket = false;
                if(mp.count(curr_key))ans+=mp[curr_key];
                else ans += '?';
                curr_key = "";
            }
            else if(inside_bracket){
                curr_key += c;
            }else{
                ans += c;
            }
        }
        return ans;
    }
};