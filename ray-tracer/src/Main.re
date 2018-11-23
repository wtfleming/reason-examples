/* Setup the HTML canvas */
let canvas: DomUtils.Canvas.t =
  DomUtils.Document.getCanvasElementById(DomUtils.Document.t, "demo");
let ctx: DomUtils.Context.t = DomUtils.Canvas.getContext2d(canvas);

let width = DomUtils.Canvas.width(canvas);
let height = DomUtils.Canvas.height(canvas);

/* If ray did not intersect anything return a color representing the location on the blue/white gradient that is the the background */
let backgroundColor = (ray: Ray.t): Vec3.t => {
  let unitDirection = Vec3.unitVector(ray.direction);
  let t = (unitDirection.y +. 1.0) *. 0.5;
  /* Lerp for the color at this point in the background with the following formula: */
  /* ​blended_value = (1-t)*start_value + t*end_value */
  Vec3.make(1.0, 1.0, 1.0)
  ->Vec3.mul(1.0 -. t)
  ->Vec3.add(Vec3.mul(Vec3.make(0.5, 0.7, 1.0), t));
};

let rec color = (ray: Ray.t, world: World.t, depth: int): Vec3.t => {
  let hitRecordOption: option(HitRecord.t) =
    World.hit(world, ray, 0.001, max_float);

  switch (hitRecordOption) {
  | None => backgroundColor(ray)
  | Some(hitRecord) =>
    if (depth < 50) {
      let result =
        switch (hitRecord.material) {
        | MetalMaterial(albedo, fuzziness) =>
          MetalMaterial.scatter(
            ray,
            hitRecord.normal,
            hitRecord.p,
            albedo,
            fuzziness,
          )
        | LambertianMaterial(albedo) =>
          LambertianMaterial.scatter(
            ray,
            hitRecord.normal,
            hitRecord.p,
            albedo,
          )
        };

      switch (result) {
      | None => Vec3.make(0.0, 0.0, 0.0)
      | Some((attenuation: Vec3.t, scattered: Ray.t)) =>
        Vec3.mulVector(attenuation, color(scattered, world, depth + 1))
      };
    } else {
      Vec3.make(0.0, 0.0, 0.0);
    }
  };
};

let world: World.t = World.make();

let lookFrom = Vec3.make(13.0, 2.0, 3.0);
let lookAt = Vec3.make(0.0, 0.0, 0.0);
let distToFocus = 10.0;
let aperture = 0.1;

let camera =
  Camera.make(
    lookFrom,
    lookAt,
    Vec3.make(0.0, 1.0, 0.0),
    20.0,
    float_of_int(width) /. float_of_int(height),
    aperture,
    distToFocus,
  );

/* Increase for a better image */
let numSamples = 25;

for (y in height - 1 downto 0) {
  for (x in 0 to width - 1) {
    let col = ref(Vec3.make(0.0, 0.0, 0.0));
    for (_ in 0 to numSamples - 1) {
      let u: float =
        (float_of_int(x) +. Js.Math.random()) /. float_of_int(width);
      let v: float =
        (float_of_int(y) +. Js.Math.random()) /. float_of_int(height);
      let ray = Camera.getRay(camera, u, v);
      col := Vec3.add(col^, color(ray, world, 0));
    };

    col := Vec3.div(col^, float_of_int(numSamples));
    col := Vec3.make(sqrt(col^.x), sqrt(col^.y), sqrt(col^.z));

    let ir = int_of_float(255.99 *. col^.x);
    let ig = int_of_float(255.99 *. col^.y);
    let ib = int_of_float(255.99 *. col^.z);

    DomUtils.Context.drawPixel(ctx, x, height - y, ir, ig, ib);
  };
};
