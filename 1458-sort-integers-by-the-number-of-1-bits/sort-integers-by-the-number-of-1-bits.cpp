class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            int pca = __builtin_popcount(a),pcb = __builtin_popcount(b);
            if(pca==pcb)return a<b;
            return pca < pcb;
        });
        return arr;
    }
};