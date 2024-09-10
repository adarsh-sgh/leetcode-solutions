/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
            List<List<Integer>> sm = IntStream.range(0, m)
            .mapToObj(i -> new ArrayList<>(Collections.nCopies(n, -1)))
            .collect(Collectors.toList());

    // top, right, bottom, left
    List<Integer> dir = List.of(-1,0,1,0,-1);
    
    int d = 1;
    int x = 0, y = 0;

   BiPredicate<Integer,Integer> oob = (i,j)-> i < 0 || j < 0 || i >= m || j >= n;
    while(head != null){
      int xn = x + dir.get(d);
      int yn = y + dir.get(d+1);
     if(oob.test(xn,yn) || sm.get(xn).get(yn) != -1){
      d++;
      d %= 4;
      xn = x + dir.get(d);
      yn = y + dir.get(d+1);
     }
     sm.get(x).set(y, head.val);
     x = xn; y = yn;
     head = head.next;
    }
    return sm.stream().map(z -> z.stream().mapToInt(i -> i).toArray()).toArray(int[][]::new);
    }
}