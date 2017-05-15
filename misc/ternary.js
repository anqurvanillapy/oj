/**
 *  Ternary
 *  =======
 *
 *  A simple hack like ternary operator in JS:
 *
 *    [foo, bar][!!someExprOrFunctionCall*1]()
 */

const assert = require('assert')

// Functions for `then' and `else'.
let thenFn = _ => 'then'
let elseFn = _ => 'else'

// Test cases.
let ok0 = _ => true
let ok1 = _ => Infinity
let ok2 = _ => 1
let eh0 = _ => undefined
let eh1 = _ => false
let eh2 = _ => 0
let eh3 = _ => NaN

// Run the tests.
assert([elseFn, thenFn][!!ok0()*1]() === 'then')
assert([elseFn, thenFn][!!ok1()*1]() === 'then')
assert([elseFn, thenFn][!!ok2()*1]() === 'then')
assert([elseFn, thenFn][!!eh0()*1]() === 'else')
assert([elseFn, thenFn][!!eh1()*1]() === 'else')
assert([elseFn, thenFn][!!eh2()*1]() === 'else')
assert([elseFn, thenFn][!!eh3()*1]() === 'else')

console.log('that\'s it!')
