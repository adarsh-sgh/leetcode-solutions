class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>se;
        for(int i = 0;(1<<i) <= 1e9;i++){
            string s = to_string(1<<i);
            sort(s.begin(), s.end());
            se.insert(s);
        }
        string ns = to_string(n);
        sort(ns.begin(), ns.end());
        return se.count(ns);
    }
};