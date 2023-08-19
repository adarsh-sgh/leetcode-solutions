func containsNearbyDuplicate(nums []int, k int) bool {
    var mp = map[int]int {}
    for i:= 0;i<len(nums);i++ {
        if value,exists := mp[nums[i]]; exists {
            if i - value <= k {return true}
        }
        mp[nums[i]] = i
    }
    return false
}