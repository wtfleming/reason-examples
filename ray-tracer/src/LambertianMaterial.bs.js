// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Ray$RayTracer = require("./Ray.bs.js");
var Vec3$RayTracer = require("./Vec3.bs.js");
var SphereUtils$RayTracer = require("./SphereUtils.bs.js");

function scatter(_rayIn, hitNormal, hitP, albedo) {
  var target = Vec3$RayTracer.add(Vec3$RayTracer.add(hitP, hitNormal), SphereUtils$RayTracer.randomVectorInUnitSphere(/* () */0));
  var scattered = Ray$RayTracer.make(hitP, Vec3$RayTracer.sub(target, hitP));
  return /* tuple */[
          albedo,
          scattered
        ];
}

exports.scatter = scatter;
/* No side effect */