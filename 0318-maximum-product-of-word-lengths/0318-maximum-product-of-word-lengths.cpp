class Solution {
public:

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<unsigned long long int>bm(n);
        for(int i = 0;i<n;i++){
            auto w = words[i];
            for(auto &&c:w){
                int x = c - 'a';
                bm[i] |= (1<<x);
            }
        }
        unsigned long ctr = 0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((bm[i] & bm[j])==0){
                ctr = max(ctr,  (words[i].size() * words[j].size()));
                }
            }
        }
        return ctr;
    }
};