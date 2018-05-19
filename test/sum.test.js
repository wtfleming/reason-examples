"use  strict";

const MathFns = require('../src/Math_fns.bs.js');

test('adds 1 + 2 to equal 3', () => {
  expect(MathFns.add(1, 2)).toBe(3);
});

