class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    int lastZero = -1;
    int prod = 1;
    vector<int>v = {1};
    void add(int num) {
       if(num == 0){
        lastZero = v.size();
        // this to prevent int overflow
        // since prod before this level wouldn't be used anyways
        prod = 1;
       }else{
        prod *= num;
       }
       v.push_back(prod);
    }
    
    int getProduct(int k) {
        if(lastZero >= (int)v.size() - k){
            // cout<<lastZero<< ' '<<v.size() - k<<endl;
            return 0;
        }
        return v.back() / v[v.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */