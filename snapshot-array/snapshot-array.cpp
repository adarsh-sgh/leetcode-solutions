class SnapshotArray {
public:
    vector<vector<pair<int,int>>>v;

    SnapshotArray(int length) {
        v.resize(length, { {0,0} });
    }
    int snap_id = 0;
    void set(int index, int val) {
        auto &x = v[index];
        if(!x.empty() && x.back().first==snap_id)x.pop_back();
        x.push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto &x = v[index];
        auto lb = upper_bound(x.begin(),x.end(),pair<int,int>{snap_id,INT_MAX});
        lb--;
        return lb->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */