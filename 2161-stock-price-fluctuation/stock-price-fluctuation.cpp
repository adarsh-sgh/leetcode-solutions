class StockPrice {
public:
    StockPrice() {
        
    }
    set<pair<int,int>>se;
    map<int,int>m;
    int inf = 1e9+5;

    void update(int timestamp, int price) {
        auto pp = m[timestamp];
        if(pp){
            auto it = se.lower_bound({pp,timestamp});
            se.erase(it);
        }
        se.insert({price,timestamp});
        m[timestamp] = price;
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return se.rbegin()->first;
    }
    
    int minimum() {
        return se.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */