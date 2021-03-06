// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Vec3$RayTracer = require("./Vec3.bs.js");
var Sphere$RayTracer = require("./Sphere.bs.js");

function hit(world, ray, tMin, tMax) {
  var closestSoFar = {
    contents: tMax
  };
  var _acc;
  var _input = world.spheres;
  while(true) {
    var input = _input;
    var acc = _acc;
    if (!input) {
      return acc;
    }
    var t = input.tl;
    var hitRec = Sphere$RayTracer.hit(input.hd, ray, tMin, closestSoFar.contents);
    if (hitRec !== undefined) {
      closestSoFar.contents = hitRec.t;
      _input = t;
      _acc = hitRec;
      continue ;
    }
    _input = t;
    continue ;
  };
}

function makeRandomSpheres(param) {
  var theSpheres = /* [] */0;
  for(var a = -5; a <= 5; ++a){
    for(var b = -5; b <= 5; ++b){
      var center = Vec3$RayTracer.make(a + 0.9 + Math.random(), 0.2, b + 0.9 + Math.random());
      if (Vec3$RayTracer.length(Vec3$RayTracer.sub(center, Vec3$RayTracer.make(4.0, 0.2, 0.0))) > 0.9) {
        var chooseMat = Math.random();
        var material = chooseMat < 0.8 ? ({
              TAG: /* LambertianMaterial */0,
              _0: Vec3$RayTracer.make(Math.random() * Math.random(), Math.random() * Math.random(), Math.random() * Math.random())
            }) : ({
              TAG: /* MetalMaterial */1,
              _0: Vec3$RayTracer.make(0.5 * (1.0 + Math.random()), 0.5 * (1.0 + Math.random()), 0.5 * (1.0 + Math.random())),
              _1: 0.5 * Math.random()
            });
        var s = Sphere$RayTracer.make(center, 0.2, material);
        theSpheres = {
          hd: s,
          tl: theSpheres
        };
      }
      
    }
  }
  return theSpheres;
}

var randomSpheres = makeRandomSpheres(undefined);

var spheresInScene_0 = Sphere$RayTracer.make(Vec3$RayTracer.make(0.0, -1000.0, 0.0), 1000.0, {
      TAG: /* LambertianMaterial */0,
      _0: Vec3$RayTracer.make(0.5, 0.5, 0.5)
    });

var spheresInScene_1 = {
  hd: Sphere$RayTracer.make(Vec3$RayTracer.make(4.0, 1.0, 0.0), 1.0, {
        TAG: /* MetalMaterial */1,
        _0: Vec3$RayTracer.make(0.7, 0.6, 0.5),
        _1: 0.0
      }),
  tl: {
    hd: Sphere$RayTracer.make(Vec3$RayTracer.make(0.0, 1.0, 1.5), 1.0, {
          TAG: /* LambertianMaterial */0,
          _0: Vec3$RayTracer.make(0.4, 0.2, 0.1)
        }),
    tl: randomSpheres
  }
};

var spheresInScene = {
  hd: spheresInScene_0,
  tl: spheresInScene_1
};

function make(param) {
  return {
          spheres: spheresInScene
        };
}

exports.hit = hit;
exports.makeRandomSpheres = makeRandomSpheres;
exports.randomSpheres = randomSpheres;
exports.spheresInScene = spheresInScene;
exports.make = make;
/* randomSpheres Not a pure module */
