'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

//---------- 数值 ----------------------------------------
Blockly.Blocks['Computing_Num'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, -32768, 65536), "NUM");
        this.setOutput(true, null);
        this.setColour("#f46e65");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Computing_Num'] = function(block) {
    var num = this.getFieldValue('NUM');
    return [num, Blockly.JavaScript.ORDER_ATOMIC];
};
//---------- 逻辑运算 ----------------------------------------
Blockly.Blocks['Computing_LogicalOperation'] = {
    init: function() {
        this.appendValueInput("NUM1")
            .setCheck(null);
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["并且", "&&"],
                ["或者", "||"]
            ]), "STATE");
        this.appendValueInput("NUM2")
            .setCheck(null);
        this.setOutput(true, null);
        this.setColour("#f46e65");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Computing_LogicalOperation'] = function(block) {
    var num1 = Blockly.JavaScript.valueToCode(this, 'NUM1', Blockly.JavaScript.ORDER_ATOMIC);
    var state = block.getFieldValue('STATE');
    var num2 = Blockly.JavaScript.valueToCode(this, 'NUM2', Blockly.JavaScript.ORDER_ATOMIC);
    return ['(' + num1 + state + num2 + ')', Blockly.JavaScript.ORDER_NONE];
};
//---------- 数学运算 ----------------------------------------
Blockly.Blocks['Computing_MathOperation'] = {
    init: function() {
        this.appendValueInput("NUM1")
            .setCheck(null);
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["+", "+"],
                ["-", "-"],
                ["*", "*"],
                ["/", "/"],
                ["%", "%"],
                ["&", "&"],
                ["|", "|"],
                ["^", "^"],
                [">>", ">>"],
                ["<<", "<<"]
            ]), "STATE");
        this.appendValueInput("NUM2")
            .setCheck(null);
        this.setOutput(true, null);
        this.setColour("#f46e65");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Computing_MathOperation'] = function(block) {
    var num1 = Blockly.JavaScript.valueToCode(this, 'NUM1', Blockly.JavaScript.ORDER_ATOMIC);
    var state = block.getFieldValue('STATE');
    var num2 = Blockly.JavaScript.valueToCode(this, 'NUM2', Blockly.JavaScript.ORDER_ATOMIC);
    return ['(' + num1 + state + num2 + ')', Blockly.JavaScript.ORDER_NONE];
};
//---------- 比较运算 ----------------------------------------
Blockly.Blocks['Computing_ComparativeOperation'] = {
    init: function() {
        this.appendValueInput("NUM1")
            .setCheck(null);
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["=", "==", ],
                ["\u2260", "!="],
                [">", ">"],
                ["<", "<"],
                ["\u2265", ">="],
                ["\u2264", "<="]
            ]), "STATE");
        this.appendValueInput("NUM2")
            .setCheck(null);
        this.setOutput(true, null);
        this.setColour("#f46e65");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Computing_ComparativeOperation'] = function(block) {
    var num1 = Blockly.JavaScript.valueToCode(this, 'NUM1', Blockly.JavaScript.ORDER_ATOMIC);
    var state = block.getFieldValue('STATE');
    var num2 = Blockly.JavaScript.valueToCode(this, 'NUM2', Blockly.JavaScript.ORDER_ATOMIC);
    return ['(' + num1 + state + num2 + ')', Blockly.JavaScript.ORDER_NONE];
};

