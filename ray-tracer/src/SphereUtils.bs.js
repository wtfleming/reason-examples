// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Vec3$RayTracer = require("./Vec3.bs.js");

function randomVectorInUnitSphere(param) {
  var randomVector = function (param) {
    return Vec3$RayTracer.sub(Vec3$RayTracer.mul(Vec3$RayTracer.make(Math.random(), Math.random(), Math.random()), 2.0), Vec3$RayTracer.make(1.0, 1.0, 1.0));
  };
  var p = randomVector(undefined);
  while(Vec3$RayTracer.squaredLength(p) >= 1.0) {
    p = randomVector(undefined);
  };
  return p;
}

exports.randomVectorInUnitSphere = randomVectorInUnitSphere;
/* No side effect */
