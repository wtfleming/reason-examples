"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
const ListUtils = require('../src/ListUtils.bs.js');

test('reverse()', () => {
  let list = ReasonArrayFns.to_list([1, 2, 3, 4, 5]);
  list = ListUtils.reverse(list);
  list = ReasonArrayFns.of_list(list);
  expect(list).toEqual([5, 4, 3, 2, 1]);
});
