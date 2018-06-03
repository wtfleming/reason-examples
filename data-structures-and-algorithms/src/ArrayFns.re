let reverse = arr : list('a) => {
  let rec doReverse = (arr, acc) =>
    switch (arr) {
    | [] => acc
    | [h, ...tail] => doReverse(tail, [h, ...acc])
    };
  doReverse(arr, []);
};
