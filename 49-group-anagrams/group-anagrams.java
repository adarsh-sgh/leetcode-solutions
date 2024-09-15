class Solution {
public List<List<String>> groupAnagrams(String[] strs) {
        //
    Map<List<Integer>, List<String>> mp = new HashMap<>();
    for (int i = 0; i < strs.length; i++) {
//      List<Integer> f = new ArrayList<>(26);
//      int[] f = new int[26];
      List<Integer> f = new ArrayList<>(Collections.nCopies(26,0));
      String s = strs[i];
      for (int j = 0; j < s.length(); j++) {
//        f.get(Character.codePointAt(s,j))
        int index = Character.codePointAt(s, j) - Character.codePointAt("a", 0);
        f.set(index, f.get(index) + 1);
      }
      if (!mp.containsKey(f)) mp.put(f, new ArrayList<>());
      mp.get(f).add(s);
    }
    return mp.values().stream().toList();
}
}