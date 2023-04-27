/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumXOR = function(nums) {
    return nums.reduce((a,c)=>a | c, 0);
};