class Solution {
public: 
    int inf = 1e9;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){
            swap(nums1,nums2);
            swap(n1,n2);
        }
        int n = n1 + n2;
        int l = 0, r = nums1.size(); 

        // edge case: all elements from nums1
        int m = 0;      
        while(l <= r){
             m = (l + r)/2;
             int left1 = (m == 0) ? -inf : nums1[m-1], right1 = (m == n1) ? inf : nums1[m];

             int left2 = (n/2 - m == 0) ? -inf: nums2[n/2 - m - 1], 
             right2 = (n/2 - m == n2) ? inf : nums2[n/2 - m];
            // take m elements from first array rest n/2 - m from second
            if(left1 > right2) {
                // move left
                r = m;
            }else if(left2 > right1){
                // move right
                l = m + 1;
            }else{
                break;
            }
        }
          int left1 = (m == 0) ? -inf : nums1[m-1], right1 = (m == n1) ? inf : nums1[m];

             int left2 = (n/2 - m == 0) ? -inf: nums2[n/2 - m - 1], 
             right2 = (n/2 - m == n2) ? inf : nums2[n/2 - m];
            //  cout<<right1 << ' '<<right2;
        if(n % 2){
            // single median
            return min(right1, right2);
        }else{
            return ((double)max(left1,left2) + min(right1, right2))/ 2.0;
        }
    }
};

// if total elements odd -> single median
// else avg of two middle elements

// 
// pick x elements from nums1
// n/2 - x from nums2


// 12  select 6 in left
// 13 then also select 6 in left 