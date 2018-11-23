let randomVectorInUnitSphere = (): Vec3.t => {
  let randomVector = () =>
    Vec3.make(Js.Math.random(), Js.Math.random(), Js.Math.random())
    ->Vec3.mul(2.0)
    ->Vec3.sub(Vec3.make(1.0, 1.0, 1.0));

  let p = ref(randomVector());
  while (Vec3.squaredLength(p^) >= 1.0) {
    p := randomVector();
  };
  p^;
};
