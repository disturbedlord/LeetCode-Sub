/**
 * @param {number} n
 * @return {number}
 */

var climbStairs = function(n) {
    
    if(n == 1)
        return 1;
    
    let first = 1;
    let second = 1;
    
    let res = 0;
    
    for(let i = 2 ; i <= n ; i++){
        res = first + second;
        first = second;
        second = res;
    }
    return res;
};