class Solution {
    int partition(vector<int>&v,int l,int r){
        int pivot = v[r];
        int i = l;
        for(int j = l;j<=r;j++){
            if(v[j]<pivot){
                swap(v[i],v[j]);
                i++;
            }
        }
        swap(v[r],v[i]);
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
       int l = 0, r = nums.size() -1;
       k = nums.size() - k + 1;
       while(l<=r){
           int p = partition(nums,l ,r );
           cout<<p;
            if(p==k-1){
                return nums[p];
            }else if(p < k-1){
                l = p+1;
            }else{
                r = p - 1;
            }
          }
          assert(false);
          return nums[l];
    }
};
