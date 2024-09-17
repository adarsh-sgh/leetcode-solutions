class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
              var m1 = Arrays.stream(s1.split(" ")).collect(Collectors.toMap(x -> x, y -> 1, (x, y) -> x + y));
    var m2 = Arrays.stream(s2.split(" ")).collect(Collectors.toMap(x -> x, y -> 1, (x, y) -> x + y));
    Set<String> ans = new HashSet<>();
    m1.keySet().stream().filter( x -> m1.get(x) == 1).filter(x -> !m2.containsKey(x)).forEach(x -> ans.add(x));
    m2.keySet().stream().filter( x -> m2.get(x) == 1).filter(x -> !m1.containsKey(x)).forEach(x -> ans.add(x));
    return ans.stream().toArray(String[]::new); 
    }
}