var se = map[int]bool {1:true}

func isHappy(n int) bool {
if v,exists := se[n]; exists{
    return v;
}else{
    sos := 0
    no := n
    for n > 0 {
        d := n % 10
        sos += d * d
        n/= 10
    }
     se[no] = false
     se[no] = isHappy(sos)
     return se[no]
}

}