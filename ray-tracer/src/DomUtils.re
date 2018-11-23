module Context = {
  type t;

  [@bs.send] external fillRect: (t, int, int, int, int) => unit = "fillRect";
  [@bs.set] external setFillStyle: (t, string) => unit = "fillStyle";
  let rgbString = (r: int, g: int, b: int) => {j|rgb($r,$g,$b)|j};
  let drawPixel = (t, x: int, y: int, r: int, g: int, b: int) => {
    setFillStyle(t, rgbString(r, g, b));
    fillRect(t, x, y, 1, 1);
  };
};

module Canvas = {
  type t;

  /* JavaScript equivalent: canvas.getContext('2d'); */
  [@bs.send]
  external getContext2d: (t, [@bs.as "2d"] _) => Context.t = "getContext";

  [@bs.get] external width: t => int = "width";
  [@bs.get] external height: t => int = "height";
};

module Document = {
  type t;
  [@bs.val] external t: t = "document";

  [@bs.send]
  external getCanvasElementById: (t, string) => Canvas.t = "getElementById";
};
