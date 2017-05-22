/**
 *  Weird array index
 *  =================
 *
 *  Originally from Google Developers: How Well Do You Know the Web? (Google I/O
 *  2017), presented by Jake Archibald and Paul Lewis.
 *  YouTube: https://youtu.be/vAgKZoGIvqs?t=39m32s
 */

const arr = new Int8Array(100)

// '.9' is not a canonical representation of a number.
// > Number('.9').toString() === '0.9'
// So it is indexed by string '.9'.
arr['.9'] = 42

// '1.0' is canonical so it is indexed '1'.
// > Number('1.0').toString() === '1'
arr['1.0'] = 42

// The following numbers could be represented canonically but an index cannot
// be a floating point number, so these are silently ignored (why not throwing
// errors...).
arr['1.1'] = 42
arr['1.2'] = 42

;['.9', '1.0', '1.1', '1.2'].forEach(i => {
  console.log(`arr['${i}'] = ${arr[i]}`)
})
