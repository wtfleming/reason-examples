type t = {
  center: Vec3.t,
  radius: float,
  material: Material.t,
};

let make = (center: Vec3.t, radius: float, material) => {
  center,
  radius,
  material,
};

let hit =
    (sphere: t, ray: Ray.t, tMin: float, tMax: float): option(HitRecord.t) => {
  let oc = Vec3.sub(ray.origin, sphere.center);
  let a: float = Vec3.dot(ray.direction, ray.direction);
  let b: float = Vec3.dot(oc, ray.direction);
  let c: float = Vec3.dot(oc, oc) -. sphere.radius *. sphere.radius;
  let discriminant: float = b *. b -. a *. c;

  if (discriminant > 0.0) {
    let temp1: float = (-. b -. sqrt(discriminant)) /. a;
    if (temp1 < tMax && temp1 > tMin) {
      let p = Ray.pointAtParameter(ray, temp1);
      let hitRecord =
        HitRecord.make(
          temp1,
          p,
          Vec3.div(Vec3.sub(p, sphere.center), sphere.radius),
          sphere.material,
        );
      Some(hitRecord);
    } else {
      let temp2 = (-. b +. sqrt(discriminant)) /. a;
      let p = Ray.pointAtParameter(ray, temp2);
      if (temp2 < tMax && temp2 > tMin) {
        let hitRecord =
          HitRecord.make(
            temp2,
            p,
            Vec3.div(Vec3.sub(p, sphere.center), sphere.radius),
            sphere.material,
          );
        Some(hitRecord);
      } else {
        None;
      };
    };
  } else {
    None;
  };
};
