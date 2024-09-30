class CustomStack {
public:
   int cap;
   int inc = 0;
   vector<array<int,2>>st;
    CustomStack(int maxSize) {
       cap = maxSize; 
    }

    void push(int x) {
        if(cap == st.size()) return;
        st.push_back({x,0});
    }
    
    int pop() {
        if(st.empty()) return - 1;
        int tp = st.back()[0];
        int itp = st.back()[1];
        st.pop_back();
        if(st.size()) st.back()[1] += itp;
        return tp + itp;
    }
    
    void increment(int k, int val) {
        if(st.empty()) return;
        k = min(k,(int)st.size());
        st[k-1][1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */