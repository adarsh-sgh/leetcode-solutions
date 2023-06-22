#include <time.h>
class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    vector<int>v;
    unordered_map<int,unordered_set<int>>m;
    bool insert(int val) {
        v.push_back(val);
        bool res = m.count(val);
        m[val].insert(v.size()-1);
        return !res;
    }
    
    bool remove(int val) {
        if(!m.count(val))return false;
        int in = *m[val].begin();
        m[val].erase(m[val].begin());
        if(m[val].empty())m.erase(val);
        if(in != v.size()-1){
            m[v.back()].insert(in);
            m[v.back()].erase(v.size()-1);
            // swap(v[in],v[v.size()-1]);
            v[in] = v.back();
        }
        v.pop_back();
        return true;
    }
    // srand(time(NULL));
    int getRandom() {
        int n = v.size();
        int in = rand() % n;
        return v[in];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */