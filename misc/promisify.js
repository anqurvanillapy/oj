/**
 *  Promisify
 *  =========
 *
 *  Available since Node.js 8.
 */

const { promisify } = require('util')
const { readFile } = require('fs')

const readFileAsync = promisify(readFile)

;(async () => {
  const fpath = process.argv[2]

  try {
    const text = await readFileAsync(fpath, { encoding: 'utf8' })
    process.stdout.write(text)
  } catch (err) {
    console.error(err)
    process.exit(1)
  }
})()
