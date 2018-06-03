"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
const List = require('../src/data-structures/List.bs.js');

test('make()', () => {
  expect(List.to_array(List.make())).toEqual([]);
  expect(List.make()).toEqual(0);
});

test('to_array()', () => {
  let list = List.make();
  list = List.cons(3, list);
  expect(List.to_array(list)).toEqual([3]);

  list = List.cons(4, list);
  expect(List.to_array(list)).toEqual([4, 3]);
});

test('to_reason_list()', () => {
  let list = List.make();
  list = List.cons(3, list);
  expect(List.to_reason_list(list)).toEqual([3, 0]);

  list = List.cons(5, list);
  expect(List.to_reason_list(list)).toEqual([5, [3, 0]]);

});

test('cons()', () => {
  let list = List.make();
  list = List.cons(3, list);
  expect(list).toEqual([3, 0]);

  list = List.cons(5, list);
  expect(list).toEqual([5, [3, 0]]);

  list = List.make();
  list = List.cons("aaaa", list);
  expect(list).toEqual(["aaaa", 0]);
});
