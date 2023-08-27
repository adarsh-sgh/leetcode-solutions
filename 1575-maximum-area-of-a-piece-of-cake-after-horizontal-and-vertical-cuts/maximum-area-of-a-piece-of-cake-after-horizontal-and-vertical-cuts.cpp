class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int vm = max(vc[0],w - vc.back()), hm = max(hc[0],h - hc.back());
        for(int i = 0;i<hc.size() - 1;i++){
            hm = max(hm,hc[i + 1] - hc[i]);
        }
        for(int i = 0;i<vc.size() - 1;i++){
            vm = max(vm,vc[i+1] - vc[i]);
        }
        int mod = 1e9 + 7;
        return 1ll * hm * vm  % mod;
    }
};