// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';


function rgbString(r, g, b) {
  return "rgb(" + r + "," + g + "," + b + ")";
}

function drawPixel(t, x, y, r, g, b) {
  t.fillStyle = rgbString(r, g, b);
  t.fillRect(x, y, 1, 1);
  
}

var Context = {
  rgbString: rgbString,
  drawPixel: drawPixel
};

var Canvas = {};

var $$Document = {};

exports.Context = Context;
exports.Canvas = Canvas;
exports.$$Document = $$Document;
/* No side effect */
