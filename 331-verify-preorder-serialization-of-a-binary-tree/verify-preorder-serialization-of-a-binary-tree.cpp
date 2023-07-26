class Solution {
public:
#define dbg(...) 42;
   bool isValidSerialization(string preorder) {

  int h = 0, co = 0;
  for (auto&& c : preorder) {
 
    if (1 + co + 1 - 2 * h <= 0)return false;
    if (c == ',') {
      co++;
      continue;
    }

    if (c == '#') h++;
  }
  dbg(h, co);
  return co + 2 - 2 * h == 0;
}
};