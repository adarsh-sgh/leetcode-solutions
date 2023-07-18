class LRUCache {
public:
    map<int,pair<int,int>>m;
    map<int,int>m2;
    int t = 0;
    int c;
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        m2.erase(m[key].first);
        m[key].first = t;
        m2[t] = key;
        t++;
        return m[key].second;
    }
    
    void put(int key, int value) {
        if(m.size() == c && !m.count(key)){
            int lruKey = m2.begin()->second;
            // cout<<lruKey<<" ";
            m2.erase(m2.begin());
            m.erase(lruKey);
        }
        if(m.count(key)){
            int time = m[key].first;
            m2.erase(time);
        }
        m[key] = {t,value};
        
        m2[t] = key;
        t++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */