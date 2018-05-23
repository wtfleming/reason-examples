/* do opening ({ characters have matching closing )} ones? */
let is_balanced = (str: Js.String.t) : bool => {
  let rec do_is_balanced = (stack, s: list(string)) =>
    switch (s) {
    | [] => Stack.is_empty(stack)
    | ["(", ...tail] => do_is_balanced(Stack.push("(", stack), tail)
    | ["{", ...tail] => do_is_balanced(Stack.push("{", stack), tail)
    | [")", ...tail] =>
      switch (Stack.pop(stack)) {
      | ("(", stack_tail) => do_is_balanced(stack_tail, tail)
      | _ => false
      }
    | ["}", ...tail] =>
      switch (Stack.pop(stack)) {
      | ("{", stack_tail) => do_is_balanced(stack_tail, tail)
      | _ => false
      }
    | [_, ...tail] => do_is_balanced(stack, tail)
    };
  do_is_balanced(Stack.make(), StringFns.string_to_list(str));
};
