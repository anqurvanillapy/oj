/**
 *  Flattening
 *  ==========
 *
 *  Single level array flattening using `map` and `reduce`.
 */

console.log(
  [0, 1, 2]
    .map(n => [n, 'foo'])
    .reduce((a, n) => a.concat(n), [])
)
