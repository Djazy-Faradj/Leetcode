/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let n2 = n;
    return function() {
        return n2++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */