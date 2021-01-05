let windowWidth = ref(0)
let windowHeight = ref(0)

// Types
type dimension = {width: float, height: float}

// Web Utils
let observeSize: (dimension => unit) => unit = %raw(`
function observeSize(callback) {
    let resob = new window.ResizeObserver((entries) => {
        const { width, height } = entries[entries.length - 1].contentRect;
        callback({ width, height });
    });
    resob.observe(document.getElementById('app'));
}
`);

// Main 
observeSize(({width, height}) => {
  windowWidth := int_of_float(width)
  windowHeight := int_of_float(height)

  let strWidth = Belt.Int.toString(int_of_float(width))
  let strHeight = Belt.Int.toString(windowWidth.contents)
  Js.log(`windowWidth: ${strWidth}, windowHeight: ${strHeight}`)
})
