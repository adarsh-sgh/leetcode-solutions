class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        for(int i = 0;i<(1<<n);i++){
            vector<vector<int>>vn;
            vector<int>vi;
            int curr = i & 1;
            for(int j = 0;j<n;j++){
                if(curr != (i >> j & 1)){
                    vn.push_back(vi);
                    vi.clear();
                    curr = (i >> j) & 1;
                }
                vi.push_back(v[j]);
            }   
            if(vi.size())vn.push_back(vi);
            // check if vn is sorted now
            for(auto &x:vn)sort(x.begin(),x.end());
            int sorted = true;
            int maxSeen = INT_MIN;
            for(auto &x:vn){
                for(auto &y:x){
                    if(y < maxSeen){
                        sorted = false;
                        break;
                    }
                    maxSeen = y;
                }
            }
            if(sorted){
                ans  = max(ans,(int) vn.size());
            }
        }
        return ans;
    }
};