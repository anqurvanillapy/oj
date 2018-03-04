/**
 *  super()
 *  =======
 *
 *  1. Deriving a base class with super() initializes `this`, throwing
 *  ReferenceError otherwise
 *  2. Use `new.target` to explicitly extend a base class but ignore its
 *  prototype
 */

class Base {
  constructor () {
    console.log(new.target) // => [Function: Devrived]
    this.foo = 42
  }
}

class Orphan extends Base {
  constructor () {
    console.log(new.target) // => [Function: Orphan]
    return Object.create(new.target.prototype)
  }

  bar () {
    console.log(this.foo) // => undefined
  }
}

class Derived extends Base {
  constructor () {
    console.log(new.target) // => [Function: Orphan]
    super()
  }

  bar () {
    console.log(this.foo) // => 42
  }
}

const orphan = new Orphan()
orphan.bar()

const derived = new Derived()
derived.bar()
