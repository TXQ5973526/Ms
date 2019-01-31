
var lineAIsContinue = true;

var head = document.getElementsByTagName('head')[0];
var script = document.createElement('script');
script.src = "msg/js/zh-hans.js";
script.type = 'text/javascript';
head.appendChild(script)

var workspace = Blockly.inject('blocklyDiv', {
                               media: './media/',
                               toolbox: document.getElementById('toolbox'),
                               zoom: {
                               controls: true,
                               wheel: true,
                               startScale: 1.5,
                               maxScale: 3,
                               minScale: 0.7,
                               scaleSpeed: 1.2
                               },
                               trashcan: true
                               });
workspace.showContextMenu_ = function() {};   //显示上下文菜单

function startRunInterpreter() {   //开始运行翻译
    lineAIsContinue = true;
    var blocks = workspace.getTopBlocks();

    if(blocks.length ==  0){
        code = "";
    }
    else{
        for(var x = 0, block; block = blocks[x]; x++) {
                code = Blockly.JavaScript.workspaceToCode(workspace);
        } 
    }

    //Cef.JS2C("startRunInterpreter()" +code);
    console.log("startRunInterpreter()" + code);
    return code;
}
/*
function BrowseFolder(id, fileName) {
  var canvasElement = document.getElementById(id);
  var MIME_TYPE = "image/png";
  var imgURL = "https://ss0.bdstatic.com/5aV1bjqh_Q23odCf/static/superman/img/logo/logo_white_fe6da1ec.png";
  var fileName = "skjfdksadjkfsa";
  var dlLink = document.createElement('a');
  dlLink.download = fileName;
  dlLink.href = imgURL;
  dlLink.dataset.downloadurl = [MIME_TYPE, dlLink.download, dlLink.href].join(':');
  document.body.appendChild(dlLink);
  dlLink.click();
  document.body.removeChild(dlLink);
}
*/
//存档xml文件
function saveXML_js(){
    var xml = Blockly.Xml.workspaceToDom(workspace);
    var xml_text = Blockly.Xml.domToText(xml);
    //Cef.JS2C("saveXML_js()" + xml_text);
    //console.log("saveXML_js()" + xml_text);
    return (xml_text);
}
//加载xml文件
function loadXML_js(xmltext){
	xmltext = decodeURIComponent(xmltext);
	var xml = Blockly.Xml.textToDom(xmltext);
	Blockly.Xml.domToWorkspace(xml, workspace);  
}


document.onmouseup=function(event) {
    startRunInterpreter();
    //alert("1111111111");
    //Cef.JS2C("Refresh()");
}
document.onkeyup = function(event) {
    event = event || window.event;
    if( event.keyCode == 13){
      //alert(event.keyCode);
      //Cef.JS2C("Refresh()");
      //startRunInterpreter();
    }
    
};

// var TranslateCheck = new Object(); 
// TranslateCheck.BoardLEDCheck = function(PinVariable) {
//     var NumFlag = (
//                   PinVariable=="1"||
//                   PinVariable=="2"||
//                   PinVariable=="3"||
//                   PinVariable=="4"
//                   )?true:false;
//     return NumFlag;
// };
// TranslateCheck.BoardLEDTranslate = function(PinVariable) {
//     switch(PinVariable){
//       case "1":return "BLEDR";
//       case "2":return "BLEDG";
//       case "3":return "BLEDY";
//       case "4":return "BLEDB";
//       default:return "";
//     }
// };