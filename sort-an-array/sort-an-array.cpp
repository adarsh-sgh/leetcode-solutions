class Solution {
public:
    void merge(vector<int>&v,int i,int mid,int j){
        vector<int>v1(v.begin()+i,v.begin()+mid+1),
        v2(v.begin()+mid+1,v.begin()+j+1);
        int p1 = 0,p2 = 0;
        for(int x = i;x<=j;x++){
            if(p2 >= v2.size())v[x] = v1[p1++];
            else if(p1 >= v1.size()) v[x] = v2[p2++];
            else if(v1[p1] < v2[p2]) v[x] = v1[p1++];
            else v[x] = v2[p2++];
        }
    }

    void mergeSort(vector<int>&v,int i,int j){
        if(i>=j)return;
        int mid = (i+j)/2;
        mergeSort(v,i,mid);
        mergeSort(v,mid+1,j);
        merge(v,i,mid,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};