class Solution {

    public int maxSum(List<Integer> nums, int k) {
        // count donators for each bit
        // then greedily make k biggest numbers one by one
        int max_bits = 32;
        int mod = 1_000_000_000 + 7;
        //  bit index , count
        Map<Integer, Integer> mp = new HashMap();
        for(int i = 0; i < nums.size();i++){
            for(int j = 0; j < max_bits;j++){
                if((nums.get(i) >> j & 1) == 1){
                    mp.put(j, mp.getOrDefault(j,0) + 1);
                }
            }
        }
        // List<Integer> ans = new ArrayList();
        long ans = 0;
        for(int i = 0;i < k;i++){
            long curr = 0;
            for(int j = max_bits;j>=0;j--){
                if(!mp.getOrDefault(j,0).equals(0)){
                    curr |= (1 << j);
                    mp.put(j, mp.get(j) - 1);
                }
            }
            ans +=  curr * curr;
            ans %= mod;
        }
        return (int)ans;
    }
}

// 