class SmallestInfiniteSet {
public:
    int rng = 1;
    set<int>st;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(st.size()){
            int ans = *st.begin();
            st.erase(st.begin());
            return ans;
        }
        return rng++;
    }
    
    void addBack(int num) {
        if(num<rng)st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */