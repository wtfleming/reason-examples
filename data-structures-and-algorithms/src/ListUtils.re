/* Functions for working with Reason lists for learning purposes, in actual code use functions from https://reasonml.github.io/api/List.html */
let reverse = (theList: list('a)): list('a) => {
  let rec doReverse = (l, acc) =>
    switch (l) {
    | [] => acc
    | [h, ...tail] => doReverse(tail, [h, ...acc])
    };
  doReverse(theList, []);
};
