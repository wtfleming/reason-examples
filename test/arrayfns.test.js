"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
const ArrayFns = require('../src/arrayfns.bs.js');

test('reverse a list', () => {
  const arr = ReasonArrayFns.to_list([1, 2, 3, 4]);
  const reversed = ArrayFns.reverse(arr);
  expect(ReasonArrayFns.of_list(reversed)).toEqual([4, 3, 2, 1]);
});
