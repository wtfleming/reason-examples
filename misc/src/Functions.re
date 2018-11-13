/* Functions with named parameters */
let printCombined = (~one, ~two) => Js.log(one ++ two);
printCombined(~one="sous", ~two="vide"); /* Outputs "sousvide" */

/* Punning */
/* If variable has same name as a named parameter, can use it like this */
let one = "foo";
printCombined(~one, ~two="bar"); /* Outputs "foobar" */

/* Functions with named parameters and default values */
/* Because of currying must provide a final unnamed parameter */
let multiply = (~x, ~y=2, ()) => x * y; /* In this case it the param is unit */
Js.log(multiply(~x=3, ())); /* Outputs "6" */

let multiplyTwo = (~x, ~y=2, _unused) => x * y; /* In this case it the param is a variable named _unused */
Js.log(multiplyTwo(~x=3, ())); /* Outputs "6" */

/* Shorten function name */
let toFixed = Js.Float.toFixedWithPrecision;
Js.log(toFixed(3.1415926, ~digits=2)); /* Outputs "3.14" */

/* Currying with named params */
let times = (~x, ~y) => x * y;
let timesTwo = times(~y=2);
let timesThree = times(~y=3);
Js.log(timesTwo(~x=5)); /* 10 */
Js.log(timesThree(~x=5)); /* 15 */
