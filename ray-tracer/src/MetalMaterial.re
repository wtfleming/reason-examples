type t;

let reflect = (v: Vec3.t, n: Vec3.t): Vec3.t => {
  let a = Vec3.mul(n, Vec3.dot(v, n) *. 2.0);
  Vec3.sub(v, a);
};

let scatter =
    (
      rayIn: Ray.t,
      hitNormal: Vec3.t,
      hitP: Vec3.t,
      albedo: Vec3.t,
      fuzziness: float,
    )
    : option((Vec3.t, Ray.t)) => {
  let fuzz = fuzziness > 1.0 ? 1.0 : fuzziness;
  let reflected = reflect(Vec3.unitVector(rayIn.direction), hitNormal);
  let scattered =
    Ray.make(
      hitP,
      Vec3.add(
        reflected,
        Vec3.mul(SphereUtils.randomVectorInUnitSphere(), fuzz),
      ),
    );
  let attenuation = albedo;

  if (Vec3.dot(scattered.direction, hitNormal) > 0.0) {
    Some((attenuation, scattered));
  } else {
    None;
  };
};
