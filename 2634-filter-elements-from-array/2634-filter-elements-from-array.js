/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const ans = [];
    arr.forEach((x,i)=>{
        if(fn(x,i)) ans.push(x);
    })
    return ans;
};