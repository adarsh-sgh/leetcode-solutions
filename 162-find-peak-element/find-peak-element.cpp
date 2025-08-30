class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        
       int l=1;
        int n=nums.size();
        if(n==1) return 0;
        if(n==2){
            return nums[0]>nums[1]?0:1;
        }
       if(nums[0]>nums[1])return 0;
       if(nums[n-1]>nums[n-2]) return n-1;
      
       int h=nums.size()-2;
       
       while(l<h){
        int mid=(h+l)/2;
        if (nums[mid]>nums[mid+1]&&nums[mid-1]<nums[mid]){
            return mid;
        }else if(nums[mid]<nums[mid+1]&&nums[mid]>nums[mid-1]){
            l=mid+1;
        }else if(nums[mid]>nums[mid+1]&&nums[mid]<nums[mid-1]){
            h=mid-1;
        }else{
            l=mid+1;
        }
       }
       return l;
    }
};