/* Strings */
let _s = "book" ++ "shelf"; /* binds "bookshelf" to variable _s */
let _s = float_of_int(3);

Js.String.length("a string"); /* Javascript string functions */

/* String interpolation */
let result = 5.43;
Js.log({j|Result is $result|j}); /* outputs "Result is 5.43" */

/* Strings with unicode */
/* WRONG, prints Prix avant reÌduction: 5.43 â¬ */
Js.log("Prix avant réduction: " ++ Js.Float.toString(5.43) ++ " €");
/* CORRECT */
Js.log(
  {js|Prix avant réduction: |js} ++ Js.Float.toString(5.43) ++ {js| €|js},
);
