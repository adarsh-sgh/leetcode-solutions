class Solution {
public:
    vector<int>v;
    int n;
    bool good(int i){
        if(i == n-1) return true;
        return v[i+1] < v[i];
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        v = arr;
        n = v.size();
        int l = 0, r = n-1;
        while(l< r){
            int mid = (l+r)/2;
            if(good(mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};