class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void Union(int a, int b){
        p[find(a)] = find(b);
    }
// component count -> dsu 
// hint: Connect a number to all its multiples less than threshold
// introducing extra nodes is not a problem, since we just need component count 
    int countComponents(vector<int>& nums, int t) {
       sort(nums.begin(),nums.end());
       p.resize(t+1);
        iota(p.begin(),p.end(),0ll);
       for(auto &x:nums){
        int v = x;
        while(v + x <= t){
           v += x; 
           Union(v,x);
        } 
       }
       int ans = 0;
    for(auto &i:nums){
        if(i > t)ans++;
        else if(p[i] == i){
            ans++;
        }
    }
    return ans;
    }
};