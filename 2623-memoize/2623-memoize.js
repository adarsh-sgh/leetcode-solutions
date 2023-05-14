/**
 * @param {Function} fn
 */
    // const dp = new Map();
   
function memoize(fn) {
     const dp = {}
    return function(...args) {
        const sarg = JSON.stringify(args)
        // if(dp.has(args)) return dp.get(args);
        // dp.set(args, fn(...args));
        // return dp.get(args);
        if(dp[sarg]!= undefined) return dp[sarg];
        dp[sarg] = fn(...args);
        return dp[sarg];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */