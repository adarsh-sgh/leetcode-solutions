class Solution {
public:
    vector<int>v;
    bool possible(int cuts,int mx){
        int sum = 0;
        for(int i = 0;i<v.size();i++){
            sum += v[i];
            if(v[i]>mx) return false;
            if(sum > mx){
                cuts--;
                if(cuts < 0) return false;
                sum = v[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 1e9;
        v = nums;
        while(l<r){
            // int mid = l + (r-l)/2;
            cout<<l<<' '<<r<<endl;
            int mid = (l + r)/2;
            if(possible(k-1,mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};