'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

Blockly.Blocks['Start_MainStart'] = {
    init: function() {
        this.jsonInit({
            "message0": "程序开始",
            "nextStatement": null,
            "colour": "#3dbd7d",
            "tooltip": "https://www.kancloud.cn/walimaker/wiki/635763",
            "helpUrl": ""
        })
    }
};
Blockly.JavaScript['Start_MainStart'] = function(block) {
    return '#include "WaLi.h"\n';
};
//--------------------------------------------------------------------
Blockly.Blocks['Start_Timer'] = {
    init: function() {
        this.jsonInit({
            "message0": "定时器开始",
            "nextStatement": null,
            "colour": "#3dbd7d",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.JavaScript['Start_Timer'] = function(block) {
    return 'TimStart:';
};
Blockly.Blocks['Start_TimerInit'] = {
    init: function() {
        this.appendValueInput("SETSTATE")
            .appendField("定时器间隔")
            .setCheck("Number");
        this.appendDummyInput()
            .appendField("毫秒");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#3dbd7d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Start_TimerInitNumber'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(1, 1, 1000, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#3dbd7d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Start_TimerInitNumber'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['Start_TimerInit'] = function(block) {
    var number = Blockly.JavaScript.valueToCode(this, 'SETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return 'TimerInit(' + number + ');\n';
};
Blockly.Blocks['Start_TimerStart'] = {
    init: function() {
        this.appendDummyInput()
            .appendField("打开定时器");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#3dbd7d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Start_TimerStart'] = function(block) {
    return 'TimerStart();\n';
};
Blockly.Blocks['Start_TimerStop'] = {
    init: function() {
        this.appendDummyInput()
            .appendField("关闭定时器");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#3dbd7d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Start_TimerStop'] = function(block) {
    return 'TimerStop();\n';
};
//--------------------------------------------------------------------
Blockly.Blocks['PerPinIn'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["IN1", "IN1"],
                ["IN2", "IN2"],
                ["IN3", "IN3"],
                ["IN4", "IN4"],
                ["IN5", "IN5"],
                ["IN6", "IN6"],
                ["IN7", "IN7"],
                ["IN8", "IN8"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['PerPinIn'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};
//--------------------------------------------------------------------
Blockly.Blocks['PerPinUART'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["U1", "U1"],
                ["U2", "U2"],
                ["U3", "U3"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['PerPinUART'] = function() {
    // Boolean values HIGH and LOW.
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};
//--------------------------------------------------------------------
Blockly.Blocks['PerHaveNot'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["有", "0"],
                ["无", "1"]
            ]), "IOSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['PerHaveNot'] = function() {
    var state = this.getFieldValue('IOSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
//--------------------------------------------------------------------
Blockly.Blocks['PerNotHave'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["有", "1"],
                ["无", "0"]
            ]), "IOSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['PerNotHave'] = function() {
    var state = this.getFieldValue('IOSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};

//--------------------------------------------------------------------
//--------------------------------------------------------------------
Blockly.Blocks['MovPinOut'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["OUT1", "OUT1"],
                ["OUT2", "OUT2"],
                ["OUT3", "OUT3"],
                ["OUT4", "OUT4"],
                ["OUT5", "OUT5"],
                ["OUT6", "OUT6"],
                ["OUT7", "OUT7"],
                ["OUT8", "OUT8"]
            ]), "PINNUM");
        this.setOutput(true, "Number");
        this.setColour("#49a9ee");
        this.setTooltip("");
    }
};
Blockly.JavaScript['MovPinOut'] = function() {
    var pin = this.getFieldValue('PINNUM');
    return [pin, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.Blocks['Movement_0_100'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(100, 0, 100, 1), "NUM");
        this.setOutput(true, null);
        this.setColour(230);
        this.setColour("#49a9ee");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_100'] = function(block) {
    var number = block.getFieldValue('NUM');
    return [number, Blockly.JavaScript.ORDER_NONE];
};