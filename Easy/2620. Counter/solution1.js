/*
Author: Djazy Faradj
Problem: 2620. Counter
Description: 
 - Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).
 

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: N/A
*/

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