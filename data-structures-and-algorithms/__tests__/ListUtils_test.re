/* https://github.com/reasonml-editor/reason-mode/issues/28 */
let a = "";

open Jest;

describe("reverse", () =>
  Expect.(
    test("reverse", () =>
      ListUtils.reverse([1, 2, 3, 4, 5])
      |> expect
      |> toEqual([5, 4, 3, 2, 1])
    )
  )
);
