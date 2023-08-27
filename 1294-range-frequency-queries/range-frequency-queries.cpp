class RangeFreqQuery {
public:
    map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
    }
    int lessCount(int x,vector<int>&v){
        return lower_bound(v.begin(),v.end(),x) - v.begin();
    }
    int query(int left, int right, int value) {
        auto &v = mp[value];
        return lessCount(right + 1,v) - lessCount(left,v);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */