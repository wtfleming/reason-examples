"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
const Stack = require('../src/data-structures/Stack.bs.js');

test('make()', () => {
  let stack = Stack.make();
  stack = ReasonArrayFns.of_list(stack);
  expect(stack).toEqual([]);
});

test('push()', () => {
  let stack = Stack.make();
  stack = Stack.push(5, stack);
  stack = Stack.push(7, stack);
  stack = ReasonArrayFns.of_list(stack);
  expect(stack).toEqual([7, 5]);
});

test('peek()', () => {
  let stack = Stack.make();
  stack = Stack.push(5, stack);
  expect(Stack.peek(stack)).toEqual(5);
  stack = Stack.push(7, stack);
  expect(Stack.peek(stack)).toEqual(7);
});

test('pop()', () => {
  let stack = Stack.make();
  stack = Stack.push(55, stack);
  expect(Stack.peek(stack)).toEqual(55);

  stack = Stack.push(74, stack);
  expect(Stack.peek(stack)).toEqual(74);

  stack = Stack.push(84, stack);
  expect(Stack.peek(stack)).toEqual(84);

  let x;
  [x, stack] = Stack.pop(stack);
  expect(x).toEqual(84);
  expect(Stack.peek(stack)).toEqual(74);

  [x, stack] = Stack.pop(stack);
  expect(x).toEqual(74);
  expect(Stack.peek(stack)).toEqual(55);

  [x, stack] = Stack.pop(stack);
  expect(x).toEqual(55);
  expect(Stack.peek(stack)).toEqual(0); // Maybe this should be an exception rather than 0?
});

