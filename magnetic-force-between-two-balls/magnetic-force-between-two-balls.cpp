class Solution {
public:
    vector<int>pos;
    int m;
    bool good(int f){
        int i = 0,cnt = 1;
        while(cnt < m){
            int ni = lower_bound(pos.begin(),pos.end(),pos[i]+f) - pos.begin();
            if(ni >= pos.size())return false;
            cnt++;
            i = ni;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int M) {
        sort(position.begin(),position.end());
        pos = position;
        m = M;
        int l = 0, r = position.back();
        while(l<r){
            int mid = (l + r + 1)/2;
            if(good(mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};