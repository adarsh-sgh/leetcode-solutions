import "unicode"
func isAlpha(c rune)bool {
    return unicode.IsLetter(c) || unicode.IsDigit(c)
}
func isPalindrome(s string) bool {
    j:= len(s) - 1
    for i:= 0;i<len(s); {
        if i>=j {break;}
        if !isAlpha(rune(s[i])) {
            i++;
            continue;
            }
        if !isAlpha(rune(s[j])) {
            j--;
            continue;
        }
        if unicode.ToLower(rune(s[i])) != unicode.ToLower(rune(s[j]))  {return false;}
        i++;
        j--;
    }
    return true;
}