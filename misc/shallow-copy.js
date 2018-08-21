/**
 *  Shallow copy
 *  ============
 *
 *  May the immutability be with objects.  It's critically important in those
 *  state containers.
 */

let foo = {i: 42}
const bar = foo // ref
bar.i = 69
console.log(foo)

foo = {i: 42}
const baz = Object.assign({}, foo) // copy
baz.i = 69
console.log(foo)

foo = {i: 42}
const qux = { ...foo } // copy, in a cool kid's way
qux.i = 69
console.log(foo)
