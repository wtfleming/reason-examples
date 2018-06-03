"use strict";

const ReasonArrayFns = require("bs-platform/lib/js/array.js");
// const ArrayFns = require('../src/arrayfns.bs.js');
const BinarySearchTree = require('../src/data-structures/BinarySearchTree.bs.js');

test('make()', () => {
  expect(BinarySearchTree.make(5)).toEqual([5, 0 , 0]);
});

test('make_empty()', () => {
  expect(BinarySearchTree.make_empty()).toEqual(0);
});


test('tree_of_array()', () => {
  expect(BinarySearchTree.tree_of_array([])).toEqual(0);
  expect(BinarySearchTree.tree_of_array([5, 6, 2, 1, 3])).toEqual([ 5, [ 2, [ 1, 0, 0 ], [ 3, 0, 0 ] ], [ 6, 0, 0 ] ]);
});

test('insert()', () => {
  let tree = BinarySearchTree.make(5);
  tree = BinarySearchTree.insert(7, tree);
  expect(tree).toEqual([5, 0, [7, 0, 0]]);
});

test('mem()', () => {
  const tree = BinarySearchTree.tree_of_array([5, 6, 2, 1, 3]);
  expect(BinarySearchTree.mem(5, tree)).toBe(true);
  expect(BinarySearchTree.mem(6, tree)).toBe(true);
  expect(BinarySearchTree.mem(2, tree)).toBe(true);
  expect(BinarySearchTree.mem(1, tree)).toBe(true);
  expect(BinarySearchTree.mem(3, tree)).toBe(true);

  expect(BinarySearchTree.mem(0, tree)).toBe(false);
  expect(BinarySearchTree.mem(4, tree)).toBe(false);
  expect(BinarySearchTree.mem(11, tree)).toBe(false);
});

test('sum()', () => {
  let tree = BinarySearchTree.tree_of_array([7, 15, 3, 1, 10]);
  expect(BinarySearchTree.sum(tree)).toBe(36);

  tree = BinarySearchTree.tree_of_array([]);
  expect(BinarySearchTree.sum(tree)).toBe(0);

  // tree = BinarySearchTree.tree_of_array(["a", "b", "c"]);
  // expect(BinarySearchTree.sum(tree)).toBe("abc");
});

test('height()', () => {
  let tree = BinarySearchTree.tree_of_array([]);
  expect(BinarySearchTree.height(tree)).toBe(0);

  tree = BinarySearchTree.tree_of_array([7, 15, 16, 1, 10]);
  expect(BinarySearchTree.height(tree)).toBe(3);

  tree = BinarySearchTree.make(10);
  expect(BinarySearchTree.height(tree)).toBe(1);
});

test('size()', () => {
  let tree = BinarySearchTree.tree_of_array([5, 6, 2, 1, 3]);
  expect(BinarySearchTree.size(tree)).toBe(5);

  tree = BinarySearchTree.tree_of_array([55]);
  expect(BinarySearchTree.size(tree)).toBe(1);

  tree = BinarySearchTree.tree_of_array([]);
  expect(BinarySearchTree.size(tree)).toBe(0);
  });

test('min()', () => {
  let tree = BinarySearchTree.tree_of_array([5, 6, 2, 1, 3]);
  expect(BinarySearchTree.min(tree)).toBe(1);

  tree = BinarySearchTree.tree_of_array([55]);
  expect(BinarySearchTree.min(tree)).toBe(55);

  tree = BinarySearchTree.tree_of_array(["c", "b", "e", "a"]);
  expect(BinarySearchTree.min(tree)).toBe("a");

  // Returning 0 as the minimum value for an empty tree is not ideal
  // maybe it should throw an exception instead?
  tree = BinarySearchTree.tree_of_array([]);
  expect(BinarySearchTree.size(tree)).toBe(0);
  });
