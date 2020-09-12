open Webapi.Dom;

let height = 480;
let width = 420;
let lastTime = ref(int_of_float(Js.Date.now()));

type gameState =
  | Playing
  | Start
  | Won
  | Lost;
type worldT = {state: gameState};

type directionT =
  | Left
  | Right
  | Up
  | Down;

type inputT = {
  mutable direction: option(directionT),
  mutable bbox: bool,
  mutable grid: bool,
};

let input = {direction: None, bbox: false, grid: false};

let rec gameloop = (ctx, world: worldT) => {
  // let now = int_of_float(Js.Date.now());
  // let dt = now - lastTime^;

  /* drawing is a side effect */
  switch (world.state) {
  | Playing => ()
  | Start => ()
  | Won => ()
  | Lost => ()
  };

  let nextWorld = world;

  lastTime := int_of_float(Js.Date.now());
  input.direction = None; /* remove the press once processed */
  Webapi.requestAnimationFrame(_ => gameloop(ctx, nextWorld));
};

let load = _ => {
  let canvas_id = "canvas";
  let canvas =
    switch (document |> Document.getElementById("canvas")) {
    | None =>
      print_endline("cant find canvas " ++ canvas_id ++ " \n");
      failwith("fail");
    | Some(el) => el
    };
  canvas |> Element.setAttribute("height", string_of_int(height) ++ "px");
  canvas |> Element.setAttribute("width", string_of_int(width) ++ "px");
  canvas
  |> Element.setAttribute(
       "style",
       "max-width: "
       ++ string_of_int(width)
       ++ "px; max-height: "
       ++ string_of_int(height)
       ++ "px",
     );
  let context = Webapi.Canvas.CanvasElement.getContext2d(canvas);
  gameloop(context, {state: Start});
};

Window.setOnLoad(window, load);

/* Keydown event handler translates a key press */
let keydown = (evt: KeyboardEvent.t) =>
  switch (int_of_string(KeyboardEvent.key(evt))) {
  | 38
  | 32
  | 87 => input.direction = Some(Up)
  | 39
  | 68 => input.direction = Some(Right)
  | 37
  | 65 => input.direction = Some(Left)
  | 40
  | 83 => input.direction = Some(Down)
  | 66 => input.bbox = !input.bbox
  | 71 => input.grid = !input.grid
  | _ => Js.log("did not find nothing: " ++ KeyboardEvent.key(evt))
  };

Window.addKeyDownEventListener(keydown);

Js.log("woot this working??");
