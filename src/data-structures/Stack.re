let make = () => [];

let push = (x, stack) => [x, ...stack];

let pop = stack =>
  switch (stack) {
  | [] => (0, []) /* maybe return None here instead, or throw an exception? */
  | [h, ...stack] => (h, stack)
  };

let peek = stack =>
  switch (stack) {
  | [] => 0
  | [h, ..._] => h
  };
