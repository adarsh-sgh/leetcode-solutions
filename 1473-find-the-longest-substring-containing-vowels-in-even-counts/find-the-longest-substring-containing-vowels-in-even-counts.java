class Solution {
    public int findTheLongestSubstring(String s) {
    int n = s.length();
    Map<Character,Integer> vmp = Map.of('a',0,'e',1,'i',2,'o',3,'u',4);
    int bm = 0;
    int ans = 0;
    Map<Integer,Integer> mp = new HashMap<>();
    mp.put(0,-1);
    for(int i = 0;i<n;i++){
      if(vmp.containsKey(s.charAt(i))) bm = bm ^ (1<<vmp.get(s.charAt(i)));
     if(mp.containsKey(bm)){
      ans = Math.max(ans, i - mp.get(bm));
     }else{
       mp.put(bm,i);
     }
    }
    return ans;
    }
}