type t = {
  origin: Vec3.t,
  direction: Vec3.t,
};

let make = (origin, direction) => {origin, direction};
let pointAtParameter = (ray: t, t: float): Vec3.t =>
  Vec3.add(ray.origin, Vec3.mul(ray.direction, t));
