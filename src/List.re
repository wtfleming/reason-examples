/* TODO implement to_array for JS unit testing to be easier */
/* implement reversing a list - rev() */
type node('a) =
  | Empty
  | Node('a, node('a));

let make = () => Empty;

let to_array = li => {
  let rec do_to_array = (acc, l) =>
    switch (l) {
    | Empty => acc
    | Node(x, next) =>
      Js.Array.push(x, acc) |> ignore; /* Note: mutates x */
      do_to_array(acc, next);
    };
  do_to_array([||], li);
};

/* Alternative implementation: */
/* let to_reason_list = arr => arr |> to_array |> Array.to_list; */
let to_reason_list = li => {
  let rec do_to_reason_list = (l, acc) =>
    switch (l) {
    | Empty => acc
    | Node(x, next) => do_to_reason_list(next, [x, ...acc])
    };
  do_to_reason_list(li, []) |> ListLabels.rev; /* reverse the list to keep ordering */
};

let cons = (x, l) =>
  switch (l) {
  | Empty => Node(x, Empty)
  | _ => Node(x, l)
  };
