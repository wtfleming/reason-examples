// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';


function printCombined(one, two) {
  console.log(one + two);
  
}

printCombined("sous", "vide");

var one = "foo";

printCombined(one, "bar");

function multiply(x, yOpt, param) {
  var y = yOpt !== undefined ? yOpt : 2;
  return Math.imul(x, y);
}

var y = 2;

console.log(Math.imul(3, y));

function multiplyTwo(x, yOpt, _unused) {
  var y = yOpt !== undefined ? yOpt : 2;
  return Math.imul(x, y);
}

var y$1 = 2;

console.log(Math.imul(3, y$1));

function toFixed(prim, prim$1) {
  return prim.toFixed(prim$1);
}

console.log((3.1415926).toFixed(2));

function times(x, y) {
  return Math.imul(x, y);
}

function timesTwo(param) {
  return (param << 1);
}

function timesThree(param) {
  return Math.imul(param, 3);
}

console.log(10);

console.log(15);

exports.printCombined = printCombined;
exports.one = one;
exports.multiply = multiply;
exports.multiplyTwo = multiplyTwo;
exports.toFixed = toFixed;
exports.times = times;
exports.timesTwo = timesTwo;
exports.timesThree = timesThree;
/*  Not a pure module */
