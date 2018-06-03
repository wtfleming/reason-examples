let make = () : list('a) => [];

let push = (x, stack) => [x, ...stack];

/* let pop = (stack: list(string)) => */
let pop = stack =>
  switch (stack) {
  | [] => raise(Not_found)
  | [h, ...stack] => (h, stack)
  };

let peek = stack =>
  switch (stack) {
  | [] => 0
  | [h, ..._] => h
  };

let is_empty = stack =>
  switch (stack) {
  | [] => true
  | _ => false
  };
