'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

Blockly.Blocks['Start_MainStart'] = {
    init: function() {
        this.jsonInit({
            "message0": "程序开始",
            "nextStatement": null,
            "colour": "#48cf4f",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.JavaScript['Start_MainStart'] = function(block) {
    // TODO: Assemble JavaScript into code variable.
    return '#include "WaLi.h"\n';
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
        this.setColour("#00ceba");
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
        this.setColour("#00ceba");
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
        this.setColour("#00ceba");
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
        this.setColour("#00ceba");
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
        this.setColour("#21c1fb");
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
        this.setColour("#21c1fb");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Movement_0_100'] = function(block) {
  var number = block.getFieldValue('NUM');
  return [number, Blockly.JavaScript.ORDER_NONE];
};