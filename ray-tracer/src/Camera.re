type t = {
  lowerLeftCorner: Vec3.t,
  horizontal: Vec3.t,
  vertical: Vec3.t,
  origin: Vec3.t,
  u: Vec3.t,
  v: Vec3.t,
  lensRadius: float,
};

let randomVectorInUnitDisk = (): Vec3.t => {
  let randomVector = () =>
    Vec3.make(Js.Math.random(), Js.Math.random(), Js.Math.random())
    ->Vec3.mul(2.0)
    ->Vec3.sub(Vec3.make(1.0, 1.0, 0.0));

  let p = ref(randomVector());
  while (Vec3.dot(p^, p^) >= 1.0) {
    p := randomVector();
  };
  p^;
};

/* vfov is top to bottom in degrees */
let make =
    (
      lookFrom: Vec3.t,
      lookAt: Vec3.t,
      vUp: Vec3.t,
      vFov: float,
      aspect: float,
      aperture: float,
      focusDistance: float,
    ) => {
  let lensRadius = aperture /. 2.0;
  let theta: float = vFov *. Js.Math._PI /. 180.0;
  let halfHeight: float = tan(theta /. 2.0);
  let halfWidth: float = aspect *. halfHeight;

  let origin = lookFrom;
  let w = Vec3.unitVector(Vec3.sub(lookFrom, lookAt));
  let u = Vec3.unitVector(Vec3.cross(vUp, w));
  let v = Vec3.cross(w, u);

  let lowerLeftCorner =
    origin
    ->Vec3.sub(Vec3.mul(u, halfWidth *. focusDistance))
    ->Vec3.sub(Vec3.mul(v, halfHeight *. focusDistance))
    ->Vec3.sub(Vec3.mul(w, focusDistance));

  let horizontal = Vec3.mul(u, 2.0 *. halfWidth *. focusDistance);
  let vertical = Vec3.mul(v, 2.0 *. halfHeight *. focusDistance);

  {lowerLeftCorner, horizontal, vertical, origin, u, v, lensRadius};
};

let getRay = (camera: t, s: float, t: float): Ray.t => {
  let rd = Vec3.mul(randomVectorInUnitDisk(), camera.lensRadius);
  let offset: Vec3.t =
    Vec3.mul(camera.u, rd.x)->Vec3.add(Vec3.mul(camera.v, rd.y));

  let rayDirection: Vec3.t =
    camera.lowerLeftCorner
    ->Vec3.add(Vec3.mul(camera.horizontal, s))
    ->Vec3.add(Vec3.mul(camera.vertical, t))
    ->Vec3.sub(camera.origin)
    ->Vec3.sub(offset);

  Ray.make(Vec3.add(camera.origin, offset), rayDirection);
};
