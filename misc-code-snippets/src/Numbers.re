/* Multiply ints */
let ints = 3 * 4;

/* Multiply floats */
let floats = 1.212 *. 3.4384;

/* Float to precision */
Js.log("Amount: $" ++ Js.Float.toFixedWithPrecision(7.24242344, ~digits=2)); /* Outputs "Amount: $7.24" */

/* Pervasives */
let _result = sqrt(abs_float(-3.75));

/* Javascript math library */
let r = 5.0;
let area = Js.Math._PI *. r *. r;
