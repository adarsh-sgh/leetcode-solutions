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

//! tc calculation is tricky, copied from discussion:

//  Time complexity: Since the elements in nums are unique. So, worst case would be when all the elements in the nums array are like this 2, 3, 4, 5, 6, ... k. So, we can say that in worst case the complexity of algorithm would be:
// th/1+th/2+th/3+th/4+th/5+...+th/k=th∗log(th) (because the max value of k could be th)
// O(max(n,th∗log(th)))
// Here th is threshold
// Reference: Sum of Harmonic Series


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