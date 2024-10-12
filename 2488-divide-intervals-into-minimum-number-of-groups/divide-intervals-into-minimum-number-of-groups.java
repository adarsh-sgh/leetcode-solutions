class Solution {
    public int minGroups(int[][] intervals) {
                // SortedSet<Integer> st = new TreeSet<>();
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        mp.put(-1, 1);
        //
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        for (int i = 0; i < intervals.length; i++) {
            // dbg(mp);
            if (mp.firstKey() >= intervals[i][0]) {
                mp.put(intervals[i][1], mp.getOrDefault(intervals[i][1], 0) + 1);
                continue;
            }
            int fk = mp.firstKey();
            if (mp.get(fk) == 1) {
                mp.remove(fk);
            } else {
                mp.put(fk, mp.get(fk) - 1);
            }
            mp.put(intervals[i][1], mp.getOrDefault(intervals[i][1], 0) + 1);

        }
        return mp.values().stream().reduce(0, (a, b) -> a + b);
    }
}