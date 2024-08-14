/**
 * @param {number} n
 * @return {Function} counter
 */

//let gVar = 0;
var createCounter = function(n) {
    let gVar = n;
    return function() {
        let t = gVar;
        gVar++;
        return t;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */