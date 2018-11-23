type t = {spheres: list(Sphere.t)};

let hit =
    (world: t, ray: Ray.t, tMin: float, tMax: float): option(HitRecord.t) => {
  let closestSoFar = ref(tMax);

  let rec doHit = (acc: option(HitRecord.t), input: list(Sphere.t)) =>
    switch (input) {
    | [] => acc
    | [h, ...t] =>
      let hitRec = Sphere.hit(h, ray, tMin, closestSoFar^);
      switch (hitRec) {
      | None => doHit(acc, t)
      | Some(x) =>
        closestSoFar := x.t;
        doHit(Some(x), t);
      };
    };
  doHit(None, world.spheres);
};

let makeRandomSpheres = (): list(Sphere.t) => {
  let theSpheres = ref([]);
  for (a in (-5) to 5) {
    /* full image is -11 to 10 */
    for (b in (-5) to 5) {
      let center =
        Vec3.make(
          float_of_int(a) +. 0.9 +. Js.Math.random(),
          0.2,
          float_of_int(b) +. 0.9 +. Js.Math.random(),
        );

      if (Vec3.sub(center, Vec3.make(4.0, 0.2, 0.0))->Vec3.length > 0.9) {
        let chooseMat = Js.Math.random();
        let material: Material.t =
          if (chooseMat < 0.8) {
            LambertianMaterial(
              Vec3.make(
                Js.Math.random() *. Js.Math.random(),
                Js.Math.random() *. Js.Math.random(),
                Js.Math.random() *. Js.Math.random(),
              ),
            );
          } else {
            MetalMaterial(
              Vec3.make(
                0.5 *. (1.0 +. Js.Math.random()),
                0.5 *. (1.0 +. Js.Math.random()),
                0.5 *. (1.0 +. Js.Math.random()),
              ),
              0.5 *. Js.Math.random(),
            );
          };

        let s = Sphere.make(center, 0.2, material);
        theSpheres := [s, ...theSpheres^];
      };
    };
  };
  theSpheres^;
};

let randomSpheres = makeRandomSpheres();

let spheresInScene = [
  Sphere.make(
    Vec3.make(0.0, -1000.0, 0.0),
    1000.0,
    LambertianMaterial(Vec3.make(0.5, 0.5, 0.5)),
  ),
  /* Sphere.make( */
  /*   Vec3.make(-4.0, 1.0, 0.0), */
  /*   1.0, */
  /*   MetalMaterial(Vec3.make(0.8, 0.8, 0.8), 0.2), */
  /* ), */
  Sphere.make(
    Vec3.make(4.0, 1.0, 0.0),
    1.0,
    MetalMaterial(Vec3.make(0.7, 0.6, 0.5), 0.0),
  ),
  Sphere.make(
    Vec3.make(0.0, 1.0, 1.5),
    1.0,
    LambertianMaterial(Vec3.make(0.4, 0.2, 0.1)),
  ),
  /* Sphere.make( */
  /*   Vec3.make(0.0, 1.0, 0.0), */
  /*   1.0, */
  /*   LambertianMaterial(Vec3.make(0.4, 0.2, 0.1)), */
  /* ), */
  ...randomSpheres,
];

let make = (): t => {spheres: spheresInScene};
