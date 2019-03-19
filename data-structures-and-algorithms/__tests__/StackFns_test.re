/* https://github.com/reasonml-editor/reason-mode/issues/28 */
let a = "";

open Jest;

describe("is_balanced", () => {
  open Expect;

  test("is_balanced", () =>
    expect(StackFns.is_balanced("{(ab()cde)}")) |> toEqual(true)
  );

  test("is_balanced", () =>
    expect(StackFns.is_balanced("{(}abcde)}")) |> toEqual(false)
  );

  test("is_balanced", () =>
    expect(StackFns.is_balanced("")) |> toEqual(true)
  );

  test("is_balanced", () =>
    expect(StackFns.is_balanced("adf32")) |> toEqual(true)
  );
});
