class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,bool>mp;
        for(auto &s:supplies)mp[s] = true;
        map<string,int>rcp;
        for(int i = 0;i< recipes.size();i++) rcp[recipes[i]] = i;
        function<bool(string)> canMake = [&](string s){
            if(mp.count(s)) return mp[s];
            mp[s] = false;
            if(!rcp.count(s)) return false;
            int i = rcp[s];
            for(auto &ing:ingredients[i]){
                if(!canMake(ing))return mp[s] = false;
            }
            return mp[s] = true;
        };
        vector<string>ans;
        for(auto &s:recipes){
            if(canMake(s))ans.push_back(s);
        }
        return ans;
    }
};