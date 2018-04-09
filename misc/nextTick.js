/**
 *  nextTick
 *  ========
 *
 *  Yet another job queue in Node.js, *next tick queue*, compared to microtask
 *  queue, task queue, etc.  It's more efficient than `setTimeout(cb, 0)` for
 *  running before any additional I/O events (e.g. timers).
 *
 *  Moreover, process.nextTick can be used to block I/O events.
 */

const fs = require('fs')

const idk = Math.random() > 0.5

const foo = (ok, cb) => {
  if (ok) {
    cb()
    return
  }

  fs.stat('file', cb)
}

const bar = (ok, cb) => {
  if (ok) {
    process.nextTick(cb)
    return
  }

  fs.stat('file', cb)
}

// foo0 and foo1 are printed indefinitely.

foo(idk, () => {
  console.log('foo1')
})

console.log('foo0')

// bar0 is definitely printed before bar1.

bar(idk, () => {
  console.log('bar1')
})

console.log('bar0')
