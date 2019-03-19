/* https://github.com/reasonml-editor/reason-mode/issues/28 */
let a = "";

open Jest;

describe("make", () =>
  Expect.(test("toBe", () =>
            expect(Stack.make()) |> toBe([])
          ))
);

describe("push and peek", () =>
  Expect.(
    test("push and peek", () =>
      Stack.make()
      |> Stack.push(2)
      |> Stack.push(3)
      |> Stack.peek
      |> expect
      |> toEqual(3)
    )
  )
);

describe("pop", () =>
  Expect.(
    test("pop", () => {
      let (x, _stack) =
        Stack.make() |> Stack.push(2) |> Stack.push(3) |> Stack.pop;
      expect(x) |> toEqual(3);
    })
  )
);

describe("is_empty", () =>
  Expect.(
    test("returns true if empty", () =>
      Stack.make() |> Stack.is_empty |> expect |> toBe(true)
    )
  )
);

describe("is_empty", () =>
  Expect.(
    test("returns true if not empty", () =>
      Stack.make()
      |> Stack.push(55)
      |> Stack.is_empty
      |> expect
      |> toBe(false)
    )
  )
);
