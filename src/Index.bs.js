// Generated by ReScript, PLEASE EDIT WITH CARE


var windowWidth = {
  contents: 0
};

var windowHeight = {
  contents: 0
};

var observeSize = (function observeSize(callback) {
    let resob = new window.ResizeObserver((entries) => {
        const { width, height } = entries[entries.length - 1].contentRect;
        callback({ width, height });
    });
    resob.observe(document.getElementById('app'));
});

observeSize(function (param) {
      var width = param.width;
      windowWidth.contents = width | 0;
      windowHeight.contents = param.height | 0;
      var strWidth = String(width | 0);
      var strHeight = String(windowWidth.contents);
      console.log("windowWidth: " + strWidth + ", windowHeight: " + strHeight);
      
    });

export {
  windowWidth ,
  windowHeight ,
  observeSize ,
  
}
/*  Not a pure module */