const cases = {}

cases.c321 = () => {
  new Promise(resolve => {
    resolve(1)
    Promise.resolve().then(() => console.log(2))
  }).then(t => console.log(t))
  console.log(3)
}

cases.c312 = () => {
  new Promise(resolve => {
    Promise.resolve().then(() => {
      resolve(1)
      Promise.resolve().then(() => console.log(2))
    })
  }).then(t => console.log(t))
  console.log(3)
}

const c = process.argv[2] || 'c321'
cases[c]()
