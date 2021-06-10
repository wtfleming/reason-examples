/* Note: This was written for learning Reason, if you need to work with the DOM, */
/* you should not define Window, Document, Canvas, etc. */
/* Use bs-webapi instead https://github.com/reasonml-community/bs-webapi-incubator */

/* Sprites modified from file at: http://files.sablab.net/Games/Angband/Angband/lib/xtra/graf/16x16.bmp  License: http://angband.oook.cz/forum/showpost.php?p=316&postcount=16  "Sounds fine to me. I did it for enjoyment at the time, I never really licensed them. I don't actually care if the tiles are altered, or if I even get credit for them. Have at it." */

module Window = {
  type t;
  [@bs.val] external t: t = "window";

  [@bs.send]
  external addEventListener: (t, string, unit => unit) => unit =
    "addEventListener";
};

module Document = {
  type t;
  [@bs.val] external t: t = "document";
};

module HtmlImageElement = {
  type t;
  [@bs.new] external make: unit => t = "Image";

  [@bs.set] external setSrc: (t, string) => unit = "src";

  [@bs.send]
  external addEventListener: (t, string, unit => unit) => unit =
    "addEventListener";

  /* Create a html <img> element, and return a promise that resolves when the */
  /* image has finished loading. */
  let loadFromSrc = imageSrc => {
    let imageEl = make();

    let loadImagePromise =
      Js.Promise.make((~resolve, ~reject) => {
        addEventListener(imageEl, "load", () => resolve(. imageEl));
        addEventListener(imageEl, "error", () =>
          reject(. Invalid_argument("Could not load image: " ++ imageSrc))
        );
      });

    setSrc(imageEl, imageSrc);
    loadImagePromise;
  };
};

module Canvas = {
  type t;
  [@bs.send]
  external getElementById: (Document.t, string) => t = "getElementById";
};

module Context = {
  type t;

  /* JavaScript equivalent: canvas.getContext('2d'); */
  [@bs.send]
  external getContext2d: (Canvas.t, [@bs.as "2d"] _) => t = "getContext";

  [@bs.send]
  external drawImage:
    (
      t,
      ~image: HtmlImageElement.t,
      ~dx: int,
      ~dy: int,
      ~dWidth: int,
      ~dHeight: int,
      ~sx: int,
      ~sy: int,
      ~sWidth: int,
      ~sHeight: int
    ) =>
    unit =
    "drawImage";
};

module SpriteAtlas = {
  type t = {
    imageElement: HtmlImageElement.t,
    spriteWidth: int,
  };

  let make = (src: string, spriteWidth: int) =>
    HtmlImageElement.loadFromSrc(src)
    |> Js.Promise.then_(imageElement =>
         Js.Promise.resolve({imageElement, spriteWidth})
       );

  let drawSprite = (~atlas: t, ~ctx, ~atlasNumber, ~x, ~y) =>
    Context.drawImage(
      ctx,
      ~image=atlas.imageElement,
      ~dx=atlasNumber * atlas.spriteWidth,
      ~dy=0, /* In this example we only support atlases with a single row of images, so this will always be 0 */
      ~dWidth=atlas.spriteWidth,
      ~dHeight=atlas.spriteWidth,
      ~sx=x,
      ~sy=y,
      ~sWidth=atlas.spriteWidth,
      ~sHeight=atlas.spriteWidth,
    );
};

module TileMap = {
  type t = {
    atlas: SpriteAtlas.t,
    numRows: int,
    numCols: int,
    tileSize: int, /* pixels */
    tiles: list(int) /* Maybe should be an array so it is mutable? */
  };

  let make = (~atlas, ~numRows, ~numCols, ~tileSize, ~tiles) => {
    atlas,
    numRows,
    numCols,
    tileSize,
    tiles,
  };

  /* Given an index in a tilemap, get the row and column as if it was a 2D array */
  let getRowAndColumn = (idx: int, tilemap: t): (int, int) => {
    let col: int = idx mod tilemap.numCols;
    let row: int =
      Js.Math.floor(float_of_int(idx) /. float_of_int(tilemap.numCols));
    (row, col);
  };

  let render = (ctx: Context.t, tilemap: t) =>
    List.iteri(
      (i, num) => {
        let (row, col) = getRowAndColumn(i, tilemap);
        SpriteAtlas.drawSprite(
          ~atlas=tilemap.atlas,
          ~ctx,
          ~atlasNumber=num,
          ~x=col * tilemap.tileSize,
          ~y=row * tilemap.tileSize,
        );
      },
      tilemap.tiles,
    );
};

let doWindowOnload = () => {
  let canvas: Canvas.t = Canvas.getElementById(Document.t, "demo");
  let ctx: Context.t = Context.getContext2d(canvas);
  SpriteAtlas.make("./tiles16.png", 16)
  /* SpriteAtlas.make("/images/reason-canvas-tilemap-1/tiles16.png", 16) */
  |> Js.Promise.then_(atlas => {
       /*     let tiles = [ */
       /*   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, */
       /*   2, 1, 1, 1, 1, 2, 5, 1, 1, 1, 1, 1, 1, 1, 1, 2, */
       /*   2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, */
       /*   2, 1, 1, 4, 1, 2, 2, 2, 2, 2, 0, 0, 0, 2, 1, 2, */
       /*   2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, */
       /*   2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, */
       /*   2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, */
       /*   0, 2, 1, 1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 2, */
       /*   0, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 3, 1, 1, 2, */
       /*   0, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 2, */
       /*   0, 2, 1, 3, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, */
       /*   0, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, */
       /*   0, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 2, */
       /*   0, 0, 2, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 5, 1, 2, */
       /*   0, 0, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, */
       /*   0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 */
       /* ]; */

       /* let tilemap = */
       /*   TileMap.make(~atlas, ~numRows=16, ~numCols=16, ~tileSize=16, ~tiles); */

       let tiles = [2, 2, 2, 3, 3, 3];
       let tilemap =
         TileMap.make(~atlas, ~numRows=2, ~numCols=3, ~tileSize=16, ~tiles);

       TileMap.render(ctx, tilemap);

       Js.Promise.resolve();
     })
  |> Js.Promise.catch(err => {
       Js.log2("Failure!", err);
       Js.Promise.resolve();
     })
  |> ignore;
};

Window.addEventListener(Window.t, "load", doWindowOnload);
