class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
        
    }
    stack<int>md;

    int next(int price) {
        v.push_back(price);
        while(!md.empty() && v[md.top()] <= price){
            md.pop();
        }
        int pgei = -1;
        if(!md.empty()) pgei = md.top();
        md.push(v.size()-1);
        return v.size() -1 - pgei;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */