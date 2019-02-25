'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

//---------- 板载LED ----------------------------------------
Blockly.Blocks['Movement_BoardLED'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("板载LED");
        this.appendDummyInput()
            .appendField("灯,状态");
        this.appendValueInput("SETSTATE")
            .setCheck("Boolean");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("https://www.taobao.com/");
    }
};
Blockly.Blocks['Movement_BoardLEDPin'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["红", "BLEDR"],
                ["绿", "BLEDG"],
                ["黄", "BLEDY"],
                ["蓝", "BLEDB"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.Blocks['Movement_BrightOut'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["亮", "0"],
                ["灭", "1"],
                ["翻转", "2"]
            ]), "LEDSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_BrightOut'] = function() {
    var state = this.getFieldValue('LEDSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_BoardLEDPin'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_BoardLED'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'SETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'BLEDState(' + pin + ',' + state + ');\n';
};
//---------- LED模块 ----------------------------------------
Blockly.Blocks['Movement_LEDLight'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("LED灯连接");
        this.appendDummyInput()
            .appendField(",状态");
        this.appendValueInput("SETSTATE")
            .setCheck("Boolean");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_LEDLight'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'SETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'WLOUTState(' + pin + ',' + state + ');\n';
};
Blockly.Blocks['Movement_LEDLightPWM'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("LED灯连接");
        this.appendDummyInput()
            .appendField(",亮度");
        this.appendValueInput("SETSTATE")
            .setCheck("Number");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_LEDLightPWM'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'SETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'LEDPWM(' + pin + ',' + state + ');\n';
};
//---------- 蜂鸣器传感器 ----------------------------------------
Blockly.Blocks['Movement_Buzzer'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("蜂鸣器连接");
        this.appendDummyInput()
            .appendField(",状态");
        this.appendValueInput("SETSTATE")
            .setCheck("Boolean");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_BuzzerState'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["响起", "0"],
                ["静默", "1"],
                ["翻转", "2"]
            ]), "BUZZERSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_BuzzerState'] = function() {
    var state = this.getFieldValue('BUZZERSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_Buzzer'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'SETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'WLOUTState(' + pin + ',' + state + ');\n';
};
//---------- 两线制马达 ----------------------------------------
Blockly.Blocks['Movement_Motor2W'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("两线制马达连接");
        this.appendDummyInput();
        this.appendValueInput("GETDIRECTION")
            .setCheck("Number")
            .appendField(",转向");
        this.appendValueInput("GETSPEED")
            .setCheck("Number")
            .appendField("速度");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_Motor2WPin'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["M1", "Motor1"],
                ["M2", "Motor2"],
                ["M3", "Motor3"],
                ["M4", "Motor4"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.Blocks['Movement_Motor2WDirection'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["正转", "Forward"],
                ["反转", "Backward"],
                ["空档", "coast"],
                ["刹车", "brake"]
            ]), "DIRECTION");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_Motor2WDirection'] = function() {
    var direction = this.getFieldValue('DIRECTION');
    return [direction, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_Motor2WPin'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_Motor2W'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var direction = Blockly.JavaScript.valueToCode(this, 'GETDIRECTION', Blockly.JavaScript.ORDER_ATOMIC);
    var speed = Blockly.JavaScript.valueToCode(this, 'GETSPEED', Blockly.JavaScript.ORDER_ATOMIC);
    return 'Motor2WSpeed(' + pin + ',' + direction + ',' + speed + ');\n';
};
//---------- 伺服马达 ----------------------------------------
Blockly.Blocks['Movement_Servo'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("伺服马达连接");
        this.appendDummyInput()
            .appendField(",角度");
        this.appendValueInput("SETANGLE")
            .setCheck("Number");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ServoNum'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(90, 0, 180, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ServoNum'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['Movement_Servo'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var angle = Blockly.JavaScript.valueToCode(this, 'SETANGLE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'ServoAngle(' + pin + ',' + angle + ');\n';
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Blockly.Blocks['Movement_ColorLEDColorRed'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#ff0000"), "COLORRED");
        this.setOutput(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ColorLEDColorGreen'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#00ff00"), "COLORGREEN");
        this.setOutput(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ColorLEDColorBlue'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#0000ff"), "COLORBLUE");
        this.setOutput(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLEDColorRed'] = function(block) {
    var red = this.getFieldValue('COLORRED');
    return [red, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_ColorLEDColorGreen'] = function(block) {
    var red = this.getFieldValue('COLORGREEN');
    return [red, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_ColorLEDColorBlue'] = function(block) {
    var red = this.getFieldValue('COLORBLUE');
    return [red, Blockly.JavaScript.ORDER_ATOMIC];
};

//-----------------------ws2812---------------------------//

Blockly.Blocks['Movement_ColorLED1'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("全彩LED*1连接");
        this.appendDummyInput()
            .appendField(",颜色");
        this.appendValueInput("SETCOLOR")
            .setCheck("Number");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLED1'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var colour = Blockly.JavaScript.valueToCode(this, 'SETCOLOR', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED_Colour(' + pin + ',"' + colour + '");\n';
};


Blockly.Blocks['Movement_ColorLED3Color'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["红色", "1"],
                ["绿色", "2"],
                ["蓝色", "3"]
            ]), "LEDSTATE");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_ColorLED3Color'] = function() {
    var state = this.getFieldValue('LEDSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};


Blockly.Blocks['Movement_ColorLED3Num'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["LED1", "1"],
                ["LED2", "2"],
                ["LED3", "3"]
            ]), "LEDSTATE");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_ColorLED3Num'] = function() {
    var state = this.getFieldValue('LEDSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};


Blockly.Blocks['Movement_ColorLED3'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("全彩LED*3连接");
        this.appendValueInput("GETLED")
            .appendField(",");
        this.appendValueInput("GETCOLOR")
            .appendField("颜色");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLED3'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var led = Blockly.JavaScript.valueToCode(block, 'GETLED', Blockly.JavaScript.ORDER_ATOMIC);
    var color = Blockly.JavaScript.valueToCode(block, 'GETCOLOR', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED3_Colour1(' + pin + ',' + led + ',"' + color + '");\n';
};


Blockly.Blocks['Movement_ColorLED3RGB'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("全彩LED*3连接");
        this.appendValueInput("SETR")
            .setCheck("Number")
            .appendField(",颜色");
        this.appendValueInput("SETG")
            .setCheck("Number");
        this.appendValueInput("SETB")
            .setCheck("Number");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLED3RGB'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var colourR = Blockly.JavaScript.valueToCode(block, 'SETR', Blockly.JavaScript.ORDER_ATOMIC);
    var colourG = Blockly.JavaScript.valueToCode(block, 'SETG', Blockly.JavaScript.ORDER_ATOMIC);
    var colourB = Blockly.JavaScript.valueToCode(block, 'SETB', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED3_Colour3(' + pin + ',"' + colourR + '","' + colourG + '","' + colourB + '");\n';
};


Blockly.Blocks['Movement_ColorLED3RGBPWM'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("全彩LED*3连接");
        this.appendValueInput("GETLED")
            .setCheck("Number")
            .appendField(",");
        this.appendValueInput("GETRGB")
            .setCheck("Number")
            .appendField("的");
        this.appendValueInput("GETPWM")
            .setCheck("Number")
            .appendField("亮度为");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLED3RGBPWM'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var led = Blockly.JavaScript.valueToCode(block, 'GETLED', Blockly.JavaScript.ORDER_ATOMIC);
    var rgb = Blockly.JavaScript.valueToCode(block, 'GETRGB', Blockly.JavaScript.ORDER_ATOMIC);
    var pwm = Blockly.JavaScript.valueToCode(block, 'GETPWM', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED3_RGB(' + pin + ',' + led + ',' + rgb + ',' + pwm + ');\n';
};


//------------------------   点阵板   ------------------------//


Blockly.Blocks['Movement_waliblocks_Lattice'] = {
    init: function() {
        this.appendDummyInput()
            .appendField("点阵板连接到")
            .appendField(new Blockly.FieldDropdown([
                ["U1", "U1"],
                ["U2", "U2"],
                ["U3", "U3"]
            ]), "GETPIN");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton1")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton2")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton3")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton4")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton5")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton6")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton7")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton8");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton9")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton10")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton11")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton12")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton13")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton14")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton15")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton16");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton17")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton18")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton19")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton20")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton21")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton22")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton23")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton24");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton25")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton26")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton27")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton28")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton29")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton30")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton31")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton32");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton33")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton34")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton35")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton36")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton37")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton38")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton39")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton40");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton41")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton42")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton43")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton44")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton45")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton46")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton47")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton48");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton49")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton50")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton51")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton52")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton53")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton54")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton55")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton56");
        this.appendDummyInput()
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton57")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton58")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton59")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton60")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton61")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton62")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton63")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "LAButton64");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_waliblocks_Lattice'] = function(block) {
    var pin = block.getFieldValue('GETPIN');
    var LAButton1 = (block.getFieldValue('LAButton1') == 'TRUE') ? 1 : 0;
    var LAButton2 = (block.getFieldValue('LAButton2') == 'TRUE') ? 1 : 0;
    var LAButton3 = (block.getFieldValue('LAButton3') == 'TRUE') ? 1 : 0;
    var LAButton4 = (block.getFieldValue('LAButton4') == 'TRUE') ? 1 : 0;
    var LAButton5 = (block.getFieldValue('LAButton5') == 'TRUE') ? 1 : 0;
    var LAButton6 = (block.getFieldValue('LAButton6') == 'TRUE') ? 1 : 0;
    var LAButton7 = (block.getFieldValue('LAButton7') == 'TRUE') ? 1 : 0;
    var LAButton8 = (block.getFieldValue('LAButton8') == 'TRUE') ? 1 : 0;

    var LAButton9 = (block.getFieldValue('LAButton9') == 'TRUE') ? 1 : 0;
    var LAButton10 = (block.getFieldValue('LAButton10') == 'TRUE') ? 1 : 0;
    var LAButton11 = (block.getFieldValue('LAButton11') == 'TRUE') ? 1 : 0;
    var LAButton12 = (block.getFieldValue('LAButton12') == 'TRUE') ? 1 : 0;
    var LAButton13 = (block.getFieldValue('LAButton13') == 'TRUE') ? 1 : 0;
    var LAButton14 = (block.getFieldValue('LAButton14') == 'TRUE') ? 1 : 0;
    var LAButton15 = (block.getFieldValue('LAButton15') == 'TRUE') ? 1 : 0;
    var LAButton16 = (block.getFieldValue('LAButton16') == 'TRUE') ? 1 : 0;

    var LAButton17 = (block.getFieldValue('LAButton17') == 'TRUE') ? 1 : 0;
    var LAButton18 = (block.getFieldValue('LAButton18') == 'TRUE') ? 1 : 0;
    var LAButton19 = (block.getFieldValue('LAButton19') == 'TRUE') ? 1 : 0;
    var LAButton20 = (block.getFieldValue('LAButton20') == 'TRUE') ? 1 : 0;
    var LAButton21 = (block.getFieldValue('LAButton21') == 'TRUE') ? 1 : 0;
    var LAButton22 = (block.getFieldValue('LAButton22') == 'TRUE') ? 1 : 0;
    var LAButton23 = (block.getFieldValue('LAButton23') == 'TRUE') ? 1 : 0;
    var LAButton24 = (block.getFieldValue('LAButton24') == 'TRUE') ? 1 : 0;

    var LAButton25 = (block.getFieldValue('LAButton25') == 'TRUE') ? 1 : 0;
    var LAButton26 = (block.getFieldValue('LAButton26') == 'TRUE') ? 1 : 0;
    var LAButton27 = (block.getFieldValue('LAButton27') == 'TRUE') ? 1 : 0;
    var LAButton28 = (block.getFieldValue('LAButton28') == 'TRUE') ? 1 : 0;
    var LAButton29 = (block.getFieldValue('LAButton29') == 'TRUE') ? 1 : 0;
    var LAButton30 = (block.getFieldValue('LAButton30') == 'TRUE') ? 1 : 0;
    var LAButton31 = (block.getFieldValue('LAButton31') == 'TRUE') ? 1 : 0;
    var LAButton32 = (block.getFieldValue('LAButton32') == 'TRUE') ? 1 : 0;

    var LAButton33 = (block.getFieldValue('LAButton33') == 'TRUE') ? 1 : 0;
    var LAButton34 = (block.getFieldValue('LAButton34') == 'TRUE') ? 1 : 0;
    var LAButton35 = (block.getFieldValue('LAButton35') == 'TRUE') ? 1 : 0;
    var LAButton36 = (block.getFieldValue('LAButton36') == 'TRUE') ? 1 : 0;
    var LAButton37 = (block.getFieldValue('LAButton37') == 'TRUE') ? 1 : 0;
    var LAButton38 = (block.getFieldValue('LAButton38') == 'TRUE') ? 1 : 0;
    var LAButton39 = (block.getFieldValue('LAButton39') == 'TRUE') ? 1 : 0;
    var LAButton40 = (block.getFieldValue('LAButton40') == 'TRUE') ? 1 : 0;

    var LAButton41 = (block.getFieldValue('LAButton41') == 'TRUE') ? 1 : 0;
    var LAButton42 = (block.getFieldValue('LAButton42') == 'TRUE') ? 1 : 0;
    var LAButton43 = (block.getFieldValue('LAButton43') == 'TRUE') ? 1 : 0;
    var LAButton44 = (block.getFieldValue('LAButton44') == 'TRUE') ? 1 : 0;
    var LAButton45 = (block.getFieldValue('LAButton45') == 'TRUE') ? 1 : 0;
    var LAButton46 = (block.getFieldValue('LAButton46') == 'TRUE') ? 1 : 0;
    var LAButton47 = (block.getFieldValue('LAButton47') == 'TRUE') ? 1 : 0;
    var LAButton48 = (block.getFieldValue('LAButton48') == 'TRUE') ? 1 : 0;

    var LAButton49 = (block.getFieldValue('LAButton49') == 'TRUE') ? 1 : 0;
    var LAButton50 = (block.getFieldValue('LAButton50') == 'TRUE') ? 1 : 0;
    var LAButton51 = (block.getFieldValue('LAButton51') == 'TRUE') ? 1 : 0;
    var LAButton52 = (block.getFieldValue('LAButton52') == 'TRUE') ? 1 : 0;
    var LAButton53 = (block.getFieldValue('LAButton53') == 'TRUE') ? 1 : 0;
    var LAButton54 = (block.getFieldValue('LAButton54') == 'TRUE') ? 1 : 0;
    var LAButton55 = (block.getFieldValue('LAButton55') == 'TRUE') ? 1 : 0;
    var LAButton56 = (block.getFieldValue('LAButton56') == 'TRUE') ? 1 : 0;

    var LAButton57 = (block.getFieldValue('LAButton57') == 'TRUE') ? 1 : 0;
    var LAButton58 = (block.getFieldValue('LAButton58') == 'TRUE') ? 1 : 0;
    var LAButton59 = (block.getFieldValue('LAButton59') == 'TRUE') ? 1 : 0;
    var LAButton60 = (block.getFieldValue('LAButton60') == 'TRUE') ? 1 : 0;
    var LAButton61 = (block.getFieldValue('LAButton61') == 'TRUE') ? 1 : 0;
    var LAButton62 = (block.getFieldValue('LAButton62') == 'TRUE') ? 1 : 0;
    var LAButton63 = (block.getFieldValue('LAButton63') == 'TRUE') ? 1 : 0;
    var LAButton64 = (block.getFieldValue('LAButton64') == 'TRUE') ? 1 : 0;
    var LAButtonNum1 = (LAButton1 << 7) | (LAButton2 << 6) | (LAButton3 << 5) | (LAButton4 << 4) | (LAButton5 << 3) | (LAButton6 << 2) | (LAButton7 << 1) | LAButton8;
    var LAButtonNum2 = (LAButton9 << 7) | (LAButton10 << 6) | (LAButton11 << 5) | (LAButton12 << 4) | (LAButton13 << 3) | (LAButton14 << 2) | (LAButton15 << 1) | LAButton16;
    var LAButtonNum3 = (LAButton17 << 7) | (LAButton18 << 6) | (LAButton19 << 5) | (LAButton20 << 4) | (LAButton21 << 3) | (LAButton22 << 2) | (LAButton23 << 1) | LAButton24;
    var LAButtonNum4 = (LAButton25 << 7) | (LAButton26 << 6) | (LAButton27 << 5) | (LAButton28 << 4) | (LAButton29 << 3) | (LAButton30 << 2) | (LAButton31 << 1) | LAButton32;
    var LAButtonNum5 = (LAButton33 << 7) | (LAButton34 << 6) | (LAButton35 << 5) | (LAButton36 << 4) | (LAButton37 << 3) | (LAButton38 << 2) | (LAButton39 << 1) | LAButton40;
    var LAButtonNum6 = (LAButton41 << 7) | (LAButton42 << 6) | (LAButton43 << 5) | (LAButton44 << 4) | (LAButton45 << 3) | (LAButton46 << 2) | (LAButton47 << 1) | LAButton48;
    var LAButtonNum7 = (LAButton49 << 7) | (LAButton50 << 6) | (LAButton51 << 5) | (LAButton52 << 4) | (LAButton53 << 3) | (LAButton54 << 2) | (LAButton55 << 1) | LAButton56;
    var LAButtonNum8 = (LAButton57 << 7) | (LAButton58 << 6) | (LAButton59 << 5) | (LAButton60 << 4) | (LAButton61 << 3) | (LAButton62 << 2) | (LAButton63 << 1) | LAButton64;

    //  return ['IRCSState(' + pin + ')== ' + LAButtonNum, Blockly.JavaScript.ORDER_NONE];
    return 'Lattice_Send(' + pin + ',' + LAButtonNum1 + ',' + LAButtonNum2 + ',' + LAButtonNum3 + ',' + LAButtonNum4 + ',' + LAButtonNum5 + ',' + LAButtonNum6 + ',' + LAButtonNum7 + ',' + LAButtonNum8 + ');\n';

};

//////////////////////////数码管/////////////////////

Blockly.Blocks['Movement_Digital_Tube1'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("数码管连接到");
        this.appendValueInput("NUM_NUM")
            .setCheck("Number")
            .appendField("数值显示");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_Digital_Tube1'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var num_num = Blockly.JavaScript.valueToCode(this, 'NUM_NUM', Blockly.JavaScript.ORDER_ATOMIC);

    return 'LD_NumSet(' + pin + ',' + num_num + ');\n';
};



Blockly.Blocks['Movement_Digital_Tube2'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("数码管连接到");


        this.appendValueInput("DT_NUM")
            .setCheck("Number")
            .appendField("第");


        this.appendValueInput("NUM_NUM")
            .setCheck("Number")
            .appendField("位显示");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_Digital_Tube2'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED = Blockly.JavaScript.valueToCode(this, 'DT_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var num_num = Blockly.JavaScript.valueToCode(this, 'NUM_NUM', Blockly.JavaScript.ORDER_ATOMIC);

    return 'LD_DanSet(' + pin + ',' + NUM_LED + ',' + num_num + ');\n';
};
Blockly.Blocks['Movement_Digital_Tube3'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("数码管连接到");


        this.appendValueInput("LED1")
            .setCheck("Number")
            .appendField("显示");
        this.appendValueInput("LED2")
            .setCheck("Number");
        this.appendValueInput("LED3")
            .setCheck("Number");
        this.appendValueInput("LED4")
            .setCheck("Number");

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};

Blockly.JavaScript['Movement_Digital_Tube3'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED1 = Blockly.JavaScript.valueToCode(this, 'LED1', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED2 = Blockly.JavaScript.valueToCode(this, 'LED2', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED3 = Blockly.JavaScript.valueToCode(this, 'LED3', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED4 = Blockly.JavaScript.valueToCode(this, 'LED4', Blockly.JavaScript.ORDER_ATOMIC);

    return 'LD_Set(' + pin + ',' + NUM_LED1 + ',' + NUM_LED2 + ',' + NUM_LED3 + ',' + NUM_LED4 + ');\n';
};


Blockly.Blocks['Movement_Digital_Tube4'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("数码管连接到");


        this.appendValueInput("LED1")
            .setCheck("Number")
            .appendField("段");
        this.appendValueInput("LED2")
            .setCheck("Number");
        this.appendValueInput("LED3")
            .setCheck("Number");
        this.appendValueInput("LED4")
            .setCheck("Number");

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};

Blockly.JavaScript['Movement_Digital_Tube4'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED1 = Blockly.JavaScript.valueToCode(this, 'LED1', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED2 = Blockly.JavaScript.valueToCode(this, 'LED2', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED3 = Blockly.JavaScript.valueToCode(this, 'LED3', Blockly.JavaScript.ORDER_ATOMIC);
    var NUM_LED4 = Blockly.JavaScript.valueToCode(this, 'LED4', Blockly.JavaScript.ORDER_ATOMIC);

    return 'LD_Set(' + pin + ',' + NUM_LED1 + ',' + NUM_LED2 + ',' + NUM_LED3 + ',' + NUM_LED4 + ');\n';
};


//-----------------------------------------------------------------

Blockly.Blocks['Movement_PinUART'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["U1", "U1"],
                ["U2", "U2"],
                ["U3", "U3"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_PinUART'] = function() {
    // Boolean values HIGH and LOW.
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};

Blockly.Blocks['Movement_DT_led_num'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["1", "1"],
                ["2", "2"],
                ["3", "3"],
                ["4", "4"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_DT_led_num'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};


Blockly.Blocks['Movement_DT_character'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["0", "0"],
                ["1", "1"],
                ["2", "2"],
                ["3", "3"],
                ["4", "4"],
                ["5", "5"],
                ["6", "6"],
                ["7", "7"],
                ["8", "8"],
                ["9", "9"],
                ["a", "0x41"],
                ["b", "0x42"],
                ["c", "0x43"],
                ["d", "0x44"],
                ["e", "0x45"],
                ["f", "0x46"],
                ["g", "0x47"],
                ["h", "0x48"],
                ["i", "0x49"],
                ["g", "0x4a"],
                ["k", "0x4b"],
                ["l", "0x4c"],
                ["m", "0x4d"],
                ["n", "0x4e"],
                ["o", "0x4f"],
                ["p", "0x50"],
                ["q", "0x51"],
                ["r", "0x52"],
                ["s", "0x53"],
                ["t", "0x54"],
                ["u", "0x55"],
                ["v", "0x56"],
                ["w", "0x57"],
                ["x", "0x58"],
                ["y", "0x59"],
                ["z", "0x5a"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_DT_character'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};

Blockly.Blocks['Movement_DT_led01'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["保持", "0x80"],
                ["A段亮", "0x81"],
                ["B段亮", "0x82"],
                ["C段亮", "0x83"],
                ["D段亮", "0x84"],
                ["E段亮", "0x85"],
                ["F段亮", "0x86"],
                ["G段亮", "0x87"],
                ["DP段亮", "0x88"],
                ["全亮", "0x89"],
                ["A段灭", "0xC1"],
                ["B段灭", "0xC2"],
                ["C段灭", "0xC3"],
                ["D段灭", "0xC4"],
                ["E段灭", "0xC5"],
                ["F段灭", "0xC6"],
                ["G段灭", "0xC7"],
                ["DP段灭", "0xC8"],
                ["全灭", "0xC9"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_DT_led01'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};



Blockly.Blocks['Movement_0_9999'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(8, 0, 9999, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_9999'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};


Blockly.Blocks['Movement_0_9'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(8, 0, 8, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_9'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};

//------------------ OLED ----------------------------------------

Blockly.Blocks['Movement_0_111'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, 0, 111, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_111'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};

Blockly.Blocks['Movement_0_7'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, 0, 7, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_7'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};

Blockly.Blocks['Movement_0_10'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, 0, 10, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_10'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};


Blockly.Blocks['Movement_OLED_Character_Size'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["大", "16"],
                ["小", "12"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_OLED_Character_Size'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};



Blockly.Blocks['Movement_OLED_Character'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["空格", "32"],
                ["!", "33"],
                ["\"", "34"],
                ["#", "35"],
                ["$", "36"],
                ["%", "37"],
                ["&", "38"],
                [" ", "39"],
                ["(", "40"],
                [")", "41"],
                ["*", "42"],
                ["+", "43"],
                [",", "44"],
                ["-", "45"],
                [".", "46"],
                ["/", "47"],
                ["0", "48"],
                ["1", "49"],
                ["2", "50"],
                ["3", "51"],
                ["4", "52"],
                ["5", "53"],
                ["6", "54"],
                ["7", "55"],
                ["8", "56"],
                ["9", "57"],
                [":", "58"],
                [";", "59"],
                ["<", "60"],
                ["=", "61"],
                [">", "62"],
                ["?", "63"],
                ["@", "64"],
                ["A", "65"],
                ["B", "66"],
                ["C", "67"],
                ["D", "68"],
                ["E", "69"],
                ["F", "70"],
                ["G", "71"],
                ["H", "72"],
                ["I", "73"],
                ["J", "74"],
                ["K", "75"],
                ["L", "76"],
                ["M", "77"],
                ["N", "78"],
                ["O", "79"],
                ["P", "80"],
                ["Q", "81"],
                ["R", "82"],
                ["S", "83"],
                ["T", "84"],
                ["U", "85"],
                ["V", "86"],
                ["W", "87"],
                ["X", "88"],
                ["Y", "89"],
                ["Z", "90"],
                ["[", "91"],
                ["\\", "92"],
                ["]", "93"],
                ["^", "94"],
                ["_", "95"],
                ["`", "96"],
                ["a", "97"],
                ["b", "98"],
                ["c", "99"],
                ["d", "100"],
                ["e", "101"],
                ["f", "102"],
                ["g", "103"],
                ["h", "104"],
                ["i", "105"],
                ["j", "106"],
                ["k", "107"],
                ["l", "108"],
                ["m", "109"],
                ["n", "110"],
                ["o", "111"],
                ["p", "112"],
                ["q", "113"],
                ["r", "114"],
                ["s", "115"],
                ["t", "116"],
                ["u", "117"],
                ["v", "118"],
                ["w", "119"],
                ["x", "120"],
                ["y", "121"],
                ["z", "122"],
                ["{", "123"],
                ["|", "124"],
                ["}", "125"],
                ["~", "126"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_OLED_Character'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};



Blockly.Blocks['Movement_waliblocksOLED_1'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        this.appendValueInput("X_NUM")
            .setCheck("Number")
            .appendField("列坐标");
        this.appendValueInput("Y_NUM")
            .setCheck("Number")
            .appendField("行坐标");

        this.appendValueInput("Ch_char_NUM")
            .setCheck("Number")
            .appendField("显示第");
        /*        this.appendDummyInput()
                    .appendField("汉字"); */

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_1'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var x_num = Blockly.JavaScript.valueToCode(this, 'X_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var y_num = Blockly.JavaScript.valueToCode(this, 'Y_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var cc_num = Blockly.JavaScript.valueToCode(this, 'Ch_char_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_PinShowCHinese(OUTPUT" + pin + "," + x_num + "," + y_num + "," + cc_num + ");\n";
    return code;
};

Blockly.Blocks['Movement_waliblocksOLED_2'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        this.appendValueInput("X_NUM")
            .setCheck("Number")
            .appendField("列坐标");
        this.appendValueInput("Y_NUM")
            .setCheck("Number")
            .appendField("行坐标");

        this.appendValueInput("char_Soze")
            .setCheck("Number")
            .appendField(" ");
        this.appendValueInput("String")
            .setCheck("Number")
            .appendField("字符  显示字符串");

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_2'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var x_num = Blockly.JavaScript.valueToCode(this, 'X_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var y_num = Blockly.JavaScript.valueToCode(this, 'Y_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var csize = Blockly.JavaScript.valueToCode(block, 'char_Soze', Blockly.JavaScript.ORDER_ATOMIC);
    var cc_num = Blockly.JavaScript.valueToCode(this, 'String', Blockly.JavaScript.ORDER_ATOMIC);
    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_PinShowString(OUTPUT" + pin + "," + x_num + "," + Y_num + ",\"" + cc_num + "\"," + csize + ");\n";
    return code;
};

Blockly.Blocks['Movement_waliblocksOLED_3'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        this.appendValueInput("X_NUM")
            .setCheck("Number")
            .appendField("列坐标");
        this.appendValueInput("Y_NUM")
            .setCheck("Number")
            .appendField("行坐标");

        this.appendValueInput("char_Soze")
            .setCheck("Number")
            .appendField(" ");
        this.appendValueInput("characternum")
            .setCheck("Number")
            .appendField("字符   字号显示");
        this.appendValueInput("NUM")
            .setCheck("Number")
            .appendField("位   数值");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_3'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var x_num = Blockly.JavaScript.valueToCode(this, 'X_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var y_num = Blockly.JavaScript.valueToCode(this, 'Y_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var csize = Blockly.JavaScript.valueToCode(block, 'char_Soze', Blockly.JavaScript.ORDER_ATOMIC);
    var c_num = Blockly.JavaScript.valueToCode(this, 'characternum', Blockly.JavaScript.ORDER_ATOMIC);
    var num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);

    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_PinShowNum(OUTPUT" + pin + "," + x_num + "," + y_num + "," + c_num + "," + num + "," + csize + ");\n";
    return code;
};


Blockly.Blocks['Movement_waliblocksOLED_4'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        this.appendValueInput("X_NUM")
            .setCheck("Number")
            .appendField("列坐标");
        this.appendValueInput("Y_NUM")
            .setCheck("Number")
            .appendField("行坐标");

        this.appendValueInput("char_Soze")
            .setCheck("Number")
            .appendField(" ");
        this.appendValueInput("character")
            .setCheck("Number")
            .appendField("字符   显示字符串");

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_4'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var x_num = Blockly.JavaScript.valueToCode(this, 'X_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var y_num = Blockly.JavaScript.valueToCode(this, 'Y_NUM', Blockly.JavaScript.ORDER_ATOMIC);
    var csize = Blockly.JavaScript.valueToCode(block, 'char_Soze', Blockly.JavaScript.ORDER_ATOMIC);
    var cc_num = Blockly.JavaScript.valueToCode(block, 'character', Blockly.JavaScript.ORDER_ATOMIC);
    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_PinShowChar(OUTPUT" + pin + "," + x_num + "," + y_num + "," + cc_num + "," + csize + ");\n";
    return code;
};

Blockly.Blocks['Movement_waliblocksOLED_5'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        this.appendDummyInput()
            .appendField("清屏");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_5'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);

    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_PinClear(OUTPUT" + pin + ");\n";
    return code;
};
Blockly.Blocks['Movement_waliblocksOLED_6'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("OLED连接到");
        /*        this.appendDummyInput()
                    .appendField("显示瓦力logo");*/

        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};


Blockly.JavaScript['Movement_waliblocksOLED_6'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);

    var code = "SETUPCODE:OLED_Init(OUTPUT" + pin + ");SETUPEND OLED_ShowPicture(OUTPUT" + pin + ");\n";
    return code;
};


//---------- 蓝牙音频控制 ----------------------------------------
Blockly.Blocks['Movement_BluetoothAudioControl'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("蓝牙音频模块连接到");
        this.appendValueInput("COMMAND")
            .appendField("，执行");
        this.appendDummyInput();
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};

Blockly.JavaScript['Movement_BluetoothAudioControl'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var command = Blockly.JavaScript.valueToCode(block, 'COMMAND', Blockly.JavaScript.ORDER_ATOMIC);
    return 'SETUPCODE:delay_init();SETUPEND NEC_Send_Command(' + pin + ',' + command + ');\n';
};

Blockly.Blocks['Movement_BluetoothAudioControlCOMMAND'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["模式选择", "NEC_Mode"],
                ["播放/暂停", "NEC_Pause_Play"],
                ["静音", "NEC_Silent"],
                ["上一首", "NEC_Prev"],
                ["下一首", "NEC_Next"],
                ["增大音量", "NEC_Increase"],
                ["减小音量", "NEC_Decrease"]
            ]), "COMMAND");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_BluetoothAudioControlCOMMAND'] = function() {
    var command = this.getFieldValue('COMMAND');
    return [command, Blockly.JavaScript.ORDER_ATOMIC];
};