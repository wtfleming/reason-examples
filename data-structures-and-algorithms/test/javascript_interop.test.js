"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
const JsInterop = require('../src/Javascript_Interop.bs.js');

test('lists and arrays', () => {
  expect(JsInterop.reasonArray).toEqual([1, 2, 3]);

  expect(JsInterop.reasonArrayFromList).toEqual([1, 2, 3]);

  // Convert a Reason list to a JS array
  expect(ReasonArrayFns.of_list(JsInterop.reasonList)).toEqual([1, 2, 3]);
});
