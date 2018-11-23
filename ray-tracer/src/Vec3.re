type t = {
  x: float,
  y: float,
  z: float,
};

let make = (x, y, z): t => {x, y, z};

let add = (vec1: t, vec2: t): t =>
  make(vec1.x +. vec2.x, vec1.y +. vec2.y, vec1.z +. vec2.z);
let sub = (vec1: t, vec2: t): t =>
  make(vec1.x -. vec2.x, vec1.y -. vec2.y, vec1.z -. vec2.z);
let div = (vec: t, f: float): t => make(vec.x /. f, vec.y /. f, vec.z /. f);
let mul = (vec: t, f: float): t => make(vec.x *. f, vec.y *. f, vec.z *. f);
let mulVector = (vec1: t, vec2: t): t =>
  make(vec1.x *. vec2.x, vec1.y *. vec2.y, vec1.z *. vec2.z);

let dot = (vec1: t, vec2: t): float =>
  vec1.x *. vec2.x +. vec1.y *. vec2.y +. vec1.z *. vec2.z;

let cross = (vec1: t, vec2: t): t =>
  make(
    vec1.y *. vec2.z -. vec2.y *. vec1.z,
    vec1.z *. vec2.x -. vec2.z *. vec1.x,
    vec1.x *. vec2.y -. vec2.x *. vec1.y,
  );

let length = vec: float =>
  sqrt(vec.x *. vec.x +. vec.y *. vec.y +. vec.z *. vec.z);
let squaredLength = vec: float =>
  vec.x *. vec.x +. vec.y *. vec.y +. vec.z *. vec.z;
let unitVector = vec: t => div(vec, length(vec));
