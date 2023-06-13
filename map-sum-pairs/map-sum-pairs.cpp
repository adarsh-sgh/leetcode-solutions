class MapSum {
public:
    map<string,int>m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    bool isPref(const string &s1,const string &s2){
        if(s1.size() >= s2.size()) return s1 == s2;
        for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto &&[x,y]:m){
            if(isPref(prefix,x)) ans +=y;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */