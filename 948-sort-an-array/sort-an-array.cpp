class Solution {
public:
    vector<int>v;
    void merge(int l,int m,int r){
        vector<int>v1,v2;
        for(int i = l;i<=m;i++)v1.push_back(v[i]);
        for(int j = m+1;j<=r;j++)v2.push_back(v[j]);
        int i = 0, j = 0;
        for(int k = l;k<=r;k++){
            if(i >= v1.size()){
                v[k] = v2[j++];
            }else if(j>=v2.size() || v2[j] >= v1[i]){
                v[k] = v1[i++];
            }else{
                v[k] = v2[j++];
            }
        }
    }

    void mergeSort(int l,int r){
        if(l>=r)return;
        int m = (l + r )>> 1;
        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        v = nums;
        mergeSort(0,nums.size()-1);
        return v;
    }
};