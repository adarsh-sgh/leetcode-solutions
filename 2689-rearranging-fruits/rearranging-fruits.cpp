class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long,long long> m1;
        map<long long,long long> m2;
        long long minel=LONG_MAX;
        for(auto &x:basket1){
               minel = min(1ll * x, minel);
               m1[x]++; 
        }
        for(auto &x:basket2){
            minel = min(1ll * x, minel);
            m2[x]++;
        }

        for(auto &x:basket1){
            if(m1.count(x) && m2.count(x)){
                long long vmin = min(m1[x], m2[x]);
                m1[x]-=vmin;
                m2[x] -= vmin;
                if(!m1[x])m1.erase(x);
                if(!m2[x])m2.erase(x);
            }
        }
        long long cst = 0;
        vector<long long>v1, v2;
        for(auto &[x,y]:m1){
            if(y&1) return -1;
            while(y--)v1.push_back(x);
        }

        for(auto &[x,y]:m2){
            if(y&1) return -1;
            while(y--)v2.push_back(x);
        }

        assert(v1.size() == v2.size());
        int i1 = 0, j1 = v1.size() - 1, i2 = 0, j2 = v2.size() - 1;
        while(i1 <= j1){
            if(v1[i1] < v2[i2]){
                cst += min({v1[i1], v2[j2], 2 * minel});
                i1+=2;
                j2-=2;
            }else{
                cst += min({v2[i2], v1[j1], 2 * minel});
                i2+=2;
                j1-=2;
            }
        }
        return cst;
        
    }
};
