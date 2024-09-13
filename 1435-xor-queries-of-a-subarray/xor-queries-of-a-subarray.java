class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
       int n = arr.length;
       int[] xp = new int[n+1];
       for(int i = 0;i<n;i++){
        xp[i+1] = xp[i] ^ arr[i];
       }
       int q = queries.length;
       int [] ans = new int[q];
       for(int i = 0;i < q;i++){
        int x = queries[i][0], y = queries[i][1];
        ans[i] = xp[y+1] ^ xp[x];
       }
       return ans;
    }
}