// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function price(size) {
  if (typeof size === "number") {
    switch (size) {
      case 0 : 
          return 11.00;
      case 1 : 
          return 12.50;
      case 2 : 
          return 14.00;
      
    }
  } else {
    return 16.00 + (size[0] - 1 | 0) * 0.50;
  }
}

function shirtSizeOfString(str) {
  switch (str) {
    case "L" : 
        return /* Large */2;
    case "M" : 
        return /* Medium */1;
    case "S" : 
        return /* Small */0;
    case "XL" : 
        return /* XLarge */[1];
    case "XXL" : 
        return /* XLarge */[2];
    case "XXXL" : 
        return /* XLarge */[3];
    case "XXXXL" : 
        return /* XLarge */[4];
    default:
      return undefined;
  }
}

var calcButton = document.getElementById("calculate");

function getValue(element) {
  var __x = Belt_Option.map(element, (function (prim) {
          return prim;
        }));
  return Belt_Option.map(__x, (function (prim) {
                return prim.value;
              }));
}

function toInt(s) {
  var exit = 0;
  var result;
  try {
    result = Caml_format.caml_int_of_string(s);
    exit = 1;
  }
  catch (raw_exn){
    var exn = Js_exn.internalToOCamlException(raw_exn);
    if (exn[0] === Caml_builtin_exceptions.failure) {
      if (exn[1] === "int_of_string") {
        return undefined;
      } else {
        throw exn;
      }
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    return result;
  }
  
}

function calculate(param) {
  var __x = getValue(Js_primitive.nullable_to_opt(document.getElementById("quantity")));
  var quantity = Belt_Option.flatMap(__x, toInt);
  var __x$1 = getValue(Js_primitive.nullable_to_opt(document.getElementById("size")));
  var __x$2 = Belt_Option.flatMap(__x$1, shirtSizeOfString);
  var unitPrice = Belt_Option.map(__x$2, price);
  var totalPrice = unitPrice !== undefined && quantity !== undefined ? unitPrice * quantity : undefined;
  var priceString = totalPrice !== undefined ? totalPrice.toFixed(2) : "";
  Belt_Option.map(Js_primitive.nullable_to_opt(document.getElementById("price")), (function (__x) {
          __x.innerText = priceString;
          return /* () */0;
        }));
  return /* () */0;
}

if (!(calcButton == null)) {
  calcButton.addEventListener("click", calculate);
}

var D = 0;

var Doc = 0;

var Elem = 0;

var calcButton$1 = (calcButton == null) ? undefined : Js_primitive.some(calcButton);

exports.D = D;
exports.Doc = Doc;
exports.Elem = Elem;
exports.price = price;
exports.shirtSizeOfString = shirtSizeOfString;
exports.calcButton = calcButton$1;
exports.getValue = getValue;
exports.toInt = toInt;
exports.calculate = calculate;
/* calcButton Not a pure module */
