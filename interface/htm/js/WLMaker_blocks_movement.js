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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
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
        this.setColour("#21c1fb");
        this.setTooltip("");
    }
};
Blockly.Blocks['Movement_BrightOut'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["亮", "1"],
                ["灭", "0"],
                ["翻转", "2"]
            ]), "LEDSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ColorLEDColorRed'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#ff0000"), "COLORRED");
        this.setOutput(true, null);
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ColorLEDColorGreen'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#00ff00"), "COLORGREEN");
        this.setOutput(true, null);
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Movement_ColorLEDColorBlue'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldColour("#0000ff"), "COLORBLUE");
        this.setOutput(true, null);
        this.setColour("#21c1fb");
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
Blockly.JavaScript['Movement_ColorLED1'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var colour = Blockly.JavaScript.valueToCode(this, 'SETCOLOR', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED_Colour(' + pin + ',' + colour + ');\n';
};
//////
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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
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
        this.setColour("#21c1fb");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_ColorLED3Num'] = function() {
    var state = this.getFieldValue('LEDSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Movement_ColorLED3'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var led = Blockly.JavaScript.valueToCode(block, 'GETLED', Blockly.JavaScript.ORDER_ATOMIC);
    var color = Blockly.JavaScript.valueToCode(block, 'GETCOLOR', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED3_Colour1(' + pin + ',' + led + ',' + color + ');\n';
};
//////
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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_ColorLED3RGB'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var colourR = block.getFieldValue('SETR');
    var colourG = block.getFieldValue('SETG');
    var colourB = block.getFieldValue('SETB');
    return 'RGBLED3_Colour3(' + pin + ',' + colourR + ',' + colourG + ',' + colourB + ');\n';
};
///////
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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
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
        this.setColour("#21c1fb");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Movement_ColorLED3Color'] = function() {
    var state = this.getFieldValue('LEDSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};

Blockly.JavaScript['Movement_ColorLED3RGBPWM'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var led = Blockly.JavaScript.valueToCode(block, 'GETLED', Blockly.JavaScript.ORDER_ATOMIC);
    var rgb = Blockly.JavaScript.valueToCode(block, 'GETRGB', Blockly.JavaScript.ORDER_ATOMIC);
    var pwm = Blockly.JavaScript.valueToCode(block, 'GETPWM', Blockly.JavaScript.ORDER_ATOMIC);
    return 'RGBLED3_RGB(' + pin + ',' + led + ',' + rgb + ',' + pwm + ');\n';
};