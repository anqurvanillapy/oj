/**
 *  async2gen
 *  =========
 *
 *  Async to generator, a helper extracted from babel.  Use generators to
 *  emulate async functions.
 */

const asyncStep = (gen, resolve, reject, _next, _throw, key, arg) => {
  let info, val

  try {
    // Generator.prototype.next() returns objects like { value: 0, done: true }.
    info = gen[key](arg)
    val = info.value
  } catch (err) {
    return reject(err)
  }

  if (info && info.done) {
    return resolve(val)
  }

  return Promise.resolve(val).then(_next, _throw)
}

const async = fn => () => {
  const self = this
  const args = arguments

  return new Promise((resolve, reject) => {
    const gen = fn.apply(self, args)

    const _next = val => {
      asyncStep(gen, resolve, reject, _next, _throw, 'next', val)
    }

    // _throw seems useless here...
    const _throw = err => {
      asyncStep(gen, resolve, reject, _next, _throw, 'throw', err)
    }

    _next(undefined)
  })
}

const foo = () => new Promise((resolve, reject) => {
  console.log('foo')
  resolve(42)
})

const bar = () => new Promise((resolve, reject) => {
  console.log('bar')
  reject(new Error('oops'))
})

const asfn = async(function * () {
  try {
    console.log(`foo done with ${yield foo()}`)
    yield bar() // `yield` as `await`
  } catch (err) {
    console.log(err)
  }
})

console.log('before asfn')
asfn()
console.log('after asfn')
