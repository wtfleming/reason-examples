/* https://github.com/reasonml-editor/reason-mode/issues/28 */
let a = "";

open Jest;

/* test('make()', () => { */
/*   expect(BinarySearchTree.make(5)).toEqual([5, 0 , 0]); */
/* }); */
describe("make", () =>
  Expect.(
    test("make", () =>
      expect(BinarySearchTree.make(5))
      |> toEqual(
           BinarySearchTree.Node(
             5,
             BinarySearchTree.Leaf,
             BinarySearchTree.Leaf,
           ),
         )
    )
  )
);

describe("make_empty", () =>
  Expect.(
    test("make_empty", () =>
      BinarySearchTree.make_empty() |> expect |> toBe(BinarySearchTree.Leaf)
    )
  )
);

describe("insert", () =>
  Expect.(
    test("insert", () =>
      BinarySearchTree.make_empty()
      |> BinarySearchTree.insert(5)
      |> expect
      |> toEqual(
           BinarySearchTree.Node(
             5,
             BinarySearchTree.Leaf,
             BinarySearchTree.Leaf,
           ),
         )
    )
  )
);

describe("mem", () => {
  open Expect;

  let tree = BinarySearchTree.tree_of_array([|5, 6, 2, 1, 3|]);

  test("returns true if value is a member", () =>
    expect(BinarySearchTree.mem(5, tree)) |> toBe(true)
  );
  test("returns true if value is a member", () =>
    expect(BinarySearchTree.mem(6, tree)) |> toBe(true)
  );
  test("returns true if value is a member", () =>
    expect(BinarySearchTree.mem(2, tree)) |> toBe(true)
  );
  test("returns true if value is a member", () =>
    expect(BinarySearchTree.mem(1, tree)) |> toBe(true)
  );
  test("returns true if value is a member", () =>
    expect(BinarySearchTree.mem(3, tree)) |> toBe(true)
  );

  test("returns false if value is not a member", () =>
    expect(BinarySearchTree.mem(0, tree)) |> toBe(false)
  );
  test("returns false if value is not a member", () =>
    expect(BinarySearchTree.mem(4, tree)) |> toBe(false)
  );
  test("returns false if value is not a member", () =>
    expect(BinarySearchTree.mem(11, tree)) |> toBe(false)
  );
});

describe("sum", () => {
  open Expect;

  test("returns the sum of integers", () =>
    BinarySearchTree.tree_of_array([|7, 15, 3, 1, 10|])
    |> BinarySearchTree.sum
    |> expect
    |> toBe(36)
  );

  test("returns the sum of integers", () =>
    BinarySearchTree.tree_of_array([||])
    |> BinarySearchTree.sum
    |> expect
    |> toBe(0)
  );
});

describe("height", () => {
  open Expect;

  test("returns 0 for an empty tree", () =>
    BinarySearchTree.tree_of_array([||])
    |> BinarySearchTree.height
    |> expect
    |> toBe(0)
  );

  test("returns the height", () =>
    BinarySearchTree.tree_of_array([|7, 15, 16, 1, 10|])
    |> BinarySearchTree.height
    |> expect
    |> toBe(3)
  );
});

describe("size", () => {
  open Expect;

  test("returns 0 for an empty tree", () =>
    BinarySearchTree.tree_of_array([||])
    |> BinarySearchTree.size
    |> expect
    |> toBe(0)
  );

  test("returns the size", () =>
    BinarySearchTree.tree_of_array([|5, 6, 2, 1, 3|])
    |> BinarySearchTree.size
    |> expect
    |> toBe(5)
  );

  test("returns the size", () =>
    BinarySearchTree.tree_of_array([|55|])
    |> BinarySearchTree.size
    |> expect
    |> toBe(1)
  );
});

describe("min", () => {
  open Expect;

  test("returns 0 for an empty tree", () =>
    BinarySearchTree.tree_of_array([|5, 6, 2, 1, 3|])
    |> BinarySearchTree.min
    |> expect
    |> toBe(1)
  );

  test("returns the size", () =>
    BinarySearchTree.tree_of_array([|55|])
    |> BinarySearchTree.min
    |> expect
    |> toBe(55)
  );
});
