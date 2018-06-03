type binarySearchTree('a) =
  | Leaf
  | Node('a, binarySearchTree('a), binarySearchTree('a));

let make_empty = () => Leaf;

let make = x => Node(x, Leaf, Leaf);

let rec insert = (x, tree) =>
  switch (tree) {
  | Leaf => Node(x, Leaf, Leaf)
  | Node(k, left, right) when x < k => Node(k, insert(x, left), right)
  | Node(k, left, right) when x > k => Node(k, left, insert(x, right))
  | _ => Node(x, Leaf, Leaf)
  };

let create_a_tree_example = () => {
  let tree = make(5) |> insert(6) |> insert(7) |> insert(1);
  Js.log(tree);
};

let tree_of_array = arr => {
  let rec do_build_tree = (acc, x) =>
    switch (x) {
    | [] => acc
    | [h, ...tail] => do_build_tree(insert(h, acc), tail)
    };
  arr |> Array.to_list |> do_build_tree(Leaf);
};

let rec mem = (x, tree) =>
  switch (tree) {
  | Leaf => false
  | Node(k, _, _) when x == k => true
  | Node(_, left, right) => mem(x, left) || mem(x, right)
  };

let rec sum = tree =>
  switch (tree) {
  | Leaf => 0
  | Node(x, left, right) => x + sum(left) + sum(right)
  };

let max = (x, y) => x > y ? x : y;

let rec height = tree =>
  switch (tree) {
  | Leaf => 0
  | Node(_, left, right) => 1 + max(height(left), height(right))
  };

let rec size = tree =>
  switch (tree) {
  | Leaf => 0
  | Node(_, left, right) => 1 + size(left) + size(right)
  };

let min = tree => {
  let rec do_min = (acc, t) =>
    switch (t) {
    | Leaf => acc
    | Node(x, left, _) => do_min(x, left)
    };
  do_min(0, tree);
};
