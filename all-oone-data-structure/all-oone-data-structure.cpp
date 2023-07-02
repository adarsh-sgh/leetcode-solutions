class AllOne {
public:
    AllOne() {
        
    }
    map<string,int>m1;
    map<int,set<string>>m2;
   void inc(string key) {
    if (m1.count(key)) {
      m2[m1[key]].erase(key);
      if (m2[m1[key]].empty()) {
        m2.erase(m1[key]);
      }
    }
    m1[key]++;
    m2[m1[key]].insert(key);
  }

  void dec(string key) {
    m2[m1[key]].erase(key);
    if (m2[m1[key]].empty()) {
      m2.erase(m1[key]);
    }
    m1[key]--;
    if (m1[key]) {
      m2[m1[key]].insert(key);

    }
    else {
      m1.erase(key);
    }
  }
    
    string getMaxKey() {
        if(m2.empty())return "";
        auto x = m2.rbegin()->second.begin();
        return *x;
        string ans = *x;
        // m1[ans]--;
        // if(m1[ans]==0)m1.erase(ans);
        // m2.rbegin()->second.erase(x);
        // if(m2.rbegin()->second.empty()){
        //     m2.erase((--m2.rbegin()).base());
        // }
        return ans;
    }
    
    string getMinKey() {
        if(m2.empty())return "";
        return *m2.begin()->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */