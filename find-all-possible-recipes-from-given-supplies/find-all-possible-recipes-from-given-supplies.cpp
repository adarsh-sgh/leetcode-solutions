class Solution {
public:
    // set<string>avail;
    map<string,bool>avail;
    map<string,vector<string>>req;
    bool canMake(string s){
        if(avail.count(s)) return avail[s];
        // s is not a recipe
        if(!req.count(s)){
            return false;
        }
        avail[s] = false;
        for(auto &&ig:req[s]){
            if(!canMake(ig)){
                return avail[s] = false;
            }
        }
        return avail[s] =  true; 
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(auto &&s:supplies){
            avail.insert({s,true});
        }
        for(int i = 0;i<recipes.size();i++){
            req[recipes[i]] = ingredients[i];
        }
        vector<string>ans;
        for(auto &&r:recipes){
            if(canMake(r)) ans.push_back(r);
        }
        return ans;
    }
};