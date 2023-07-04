class Solution {
public:
   string s, p;
bool matcho(int i, int j) {

  if (i == s.size() && j == p.size()) return true;
  if (i == s.size() && j == p.size() - 1 && p.back() == '*') return true;
  if (i == s.size() || j == p.size()) return false;
  if (s[i] == p[j] || p[j] == '.')return match(i + 1, j + 1);
  else if (p[j] == '*') return match(i, j - 1) || match(i, j + 1);
   if(j!=s.size()-1 && p[j+1]=='*') return match(i,j+2);

  return false;
}
bool match(int i, int j) {
if (j>0 && p[j] == '*') {
    if (match(i, j - 2)) return true;
  }
  if (i == -1 && j == -1) return true;
  if (i == -1 || j == -1) return false;
  
  if (s[i] == p[j]||p[j]=='.') return match(i - 1, j - 1);
  else if(p[j]=='*' && (s[i]==p[j-1]||p[j-1]=='.'))return match(i-1,j);
 
  return false;
}

bool isMatch(string S, string P) {
  s = S;
  p = P;
//   return match(0, 0);
return match(s.size()-1,p.size()-1);
}
};