type t = {
  t: float,
  p: Vec3.t,
  normal: Vec3.t,
  material: Material.t,
};

let make = (t, p, normal, material) => {t, p, normal, material};
