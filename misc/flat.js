/**
 *  Flattening
 *  ==========
 *
 *  Single level array flattening using `map` and `reduce`.  E.g. for appending
 *  `<hr />`s to an array of VDOM components while following every element.
 */

console.log(
  [0, 1, 2]
    .map(n => [n, 'foo'])
    .reduce((a, n) => a.concat(n), [])
)
