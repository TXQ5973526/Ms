'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

//---------- 数值 ----------------------------------------
Blockly.Blocks['Functions_Num'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, -32768, 32767), "NUM");
        this.setOutput(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_Num'] = function(block) {
    var num = this.getFieldValue('NUM');
    return [num, Blockly.JavaScript.ORDER_ATOMIC];
};

//---------- 延时_秒 ----------------------------------------
Blockly.Blocks['Functions_DelayS'] = {
    init: function() {
        this.appendValueInput("NUM")
            .setCheck(null)
            .appendField("等待");
        this.appendDummyInput()
            .appendField("秒");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Functions_DelayNum'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(1, 0, 10000), "NUM");
        this.setOutput(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_DelayNum'] = function(block) {
    var num = this.getFieldValue('NUM');
    return [num, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Functions_DelayS'] = function(block) {
    var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
    return "delay_s(" + value_num + ");\n";
};
//---------- 延时_毫秒 ----------------------------------------
Blockly.Blocks['Functions_DelayMs'] = {
    init: function() {
        this.appendValueInput("NUM")
            .setCheck(null)
            .appendField("等待");
        this.appendDummyInput()
            .appendField("毫秒");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_DelayMs'] = function(block) {
    var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
    return "delay_ms(" + value_num + ");\n";
};
//---------- 延时_微妙 ----------------------------------------
Blockly.Blocks['Functions_DelayUs'] = {
    init: function() {
        this.appendValueInput("NUM")
            .setCheck(null)
            .appendField("等待");
        this.appendDummyInput()
            .appendField("微秒");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_DelayUs'] = function(block) {
    var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
    return "delay_us(" + value_num + ");\n";;
};
//---------- 随机数 ----------------------------------------
Blockly.Blocks['Functions_Random'] = {
    init: function() {
        this.appendValueInput("NUM1")
            .setCheck(null)
            .appendField("获取随机数，区间[");
        this.appendValueInput("NUM2")
            .setCheck(null)
            .appendField(",");
        this.appendDummyInput()
            .appendField("]");
        this.setOutput(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_Random'] = function(block) {
    var num1 = Blockly.JavaScript.valueToCode(this, 'NUM1', Blockly.JavaScript.ORDER_ATOMIC);
    var num2 = Blockly.JavaScript.valueToCode(this, 'NUM2', Blockly.JavaScript.ORDER_ATOMIC);
    return ['RandomNum(' + num1 + "," + num2 + ')', Blockly.JavaScript.ORDER_NONE];
};

//--------------------------------------------------------------------
Blockly.Blocks['Functions_PrintfInit'] = {
    init: function() {
        this.appendDummyInput()
            .appendField("串口打印初始化");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_PrintfInit'] = function(block) {
    return 'PrintfInit();\n';
};
Blockly.Blocks['Functions_PrintfVariable'] = {
    init: function() {
        this.appendValueInput("NUM")
            .appendField("串口打印")
            .setCheck("Number")
            .appendField(new Blockly.FieldDropdown([
                ["int型", "%d"],
                ["char型", "%c"],
                ["float型", "%f"]
            ]), "STATUS")
            .appendField(",值为");
        this.appendDummyInput();


        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_PrintfVariable'] = function(block) {
    var status = block.getFieldValue('STATUS');
    var num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
    return 'printf("' + status + '",' + num + ');\n';
};
Blockly.Blocks['Functions_PrintfString'] = {
    init: function() {
        this.appendDummyInput()
            .appendField("串口打印文字")
            .appendField(new Blockly.FieldTextInput("String"), "STRING");
        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_PrintfString'] = function(block) {
    var text_string = block.getFieldValue('STRING');
    return 'printf("' + text_string + '");\n';;
};
Blockly.Blocks['Functions_PrintfVariable'] = {
    init: function() {
        this.appendValueInput("NUM")
            .appendField("串口打印")
            .setCheck("Number")
            .appendField(new Blockly.FieldDropdown([
                ["int型", "%d"],
                ["char型", "%c"],
                ["float型", "%f"]
            ]), "STATUS")
            .appendField(",值为");
        this.appendDummyInput();


        this.setPreviousStatement(true, null);
        this.setNextStatement(true, null);
        this.setColour("#f78e3d");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Functions_PrintfVariable'] = function(block) {
    var status = block.getFieldValue('STATUS');
    var num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
    return 'printf("' + status + '",' + num + ');\n';
};
