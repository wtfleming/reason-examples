"use strict";

const StackFns = require('../src//StackFns.bs.js');

test('is_balanced()', () => {
  expect(StackFns.is_balanced("{(ab()cde)}")).toEqual(true);
  expect(StackFns.is_balanced("{(}abcde)}")).toEqual(false);

  expect(StackFns.is_balanced("")).toEqual(true);
  expect(StackFns.is_balanced("adf32")).toEqual(true);
});
