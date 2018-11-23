type t;

let scatter =
    (_rayIn: Ray.t, hitNormal: Vec3.t, hitP: Vec3.t, albedo: Vec3.t)
    : option((Vec3.t, Ray.t)) => {
  let target: Vec3.t =
    hitP
    ->Vec3.add(hitNormal)
    ->Vec3.add(SphereUtils.randomVectorInUnitSphere());

  let scattered = Ray.make(hitP, Vec3.sub(target, hitP));
  let attenuation = albedo;
  Some((attenuation, scattered));
};
