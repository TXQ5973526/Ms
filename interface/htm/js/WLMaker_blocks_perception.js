'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');


//---------- 触碰开关 ----------------------------------------
Blockly.Blocks['Perception_Button'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("触碰传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Perception_ButtonState'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["按下", "0"],
                ["抬起", "1"]
            ]), "BUTTONSTATE");
        this.setOutput(true, "Boolean");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Perception_ButtonState'] = function() {
    var state = this.getFieldValue('BUTTONSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Perception_Button'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 声音传感器 ----------------------------------------
Blockly.Blocks['Perception_Sound'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("声音传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Sound'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 红外传感器 ----------------------------------------
Blockly.Blocks['Perception_InfraredSensor'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("红外传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_InfraredSensor'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 红外遥控器 ----------------------------------------
Blockly.Blocks['Perception_IRRemoteControl'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("红外遥控器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Number");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("按下时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Perception_IRRemoteControlButton'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["按键1", "IR_Button1"],
                ["按键2", "IR_Button2"],
                ["按键3", "IR_Button3"],
                ["按键4", "IR_Button4"],
                ["按键5", "IR_Button5"],
                ["按键6", "IR_Button6"],
                ["无按键", "IR_ButtonNO"]
            ]), "BUTTONSTATE");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Perception_IRRemoteControlButton'] = function() {
    var state = this.getFieldValue('BUTTONSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Perception_IRRemoteControl'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['IRCSState(' + pin + ')== ' + state, Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_IRRemoteControl_2'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("红外遥控器连接");
        this.appendDummyInput()
            .appendField(",当按键1")
            .appendField(new Blockly.FieldCheckbox("TRUE"), "IRBUTTON1")
            .appendField("按键2")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "IRBUTTON2")
            .appendField("按键3")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "IRBUTTON3")
            .appendField("按键4")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "IRBUTTON4")
            .appendField("按键5")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "IRBUTTON5")
            .appendField("按键6")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "IRBUTTON6")
            .appendField("按下时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_IRRemoteControl_2'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var IRButton1 = block.getFieldValue('IRBUTTON1') == 'TRUE';
    var IRButton2 = block.getFieldValue('IRBUTTON2') == 'TRUE';
    var IRButton3 = block.getFieldValue('IRBUTTON3') == 'TRUE';
    var IRButton4 = block.getFieldValue('IRBUTTON4') == 'TRUE';
    var IRButton5 = block.getFieldValue('IRBUTTON5') == 'TRUE';
    var IRButton6 = block.getFieldValue('IRBUTTON6') == 'TRUE';
    var IRButtonNum = (IRButton1 << 7) | (IRButton2 << 6) | (IRButton3 << 5) | (IRButton4 << 4) | (IRButton5 << 3) | (IRButton6 << 2);
    return ['IRCSState(' + pin + ')== ' + IRButtonNum, Blockly.JavaScript.ORDER_NONE];
};
//---------- 电位器 ----------------------------------------
Blockly.Blocks['Perception_Potentiometer'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("电位器连接");
        this.appendDummyInput()
            .appendField(",采集模拟值");
        this.setOutput(true, "Number");
        this.setColour("#018997");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Potentiometer'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['ADCGet(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};
//---------- 火焰传感器 ----------------------------------------
Blockly.Blocks['Perception_FlameSensor_Analog'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("火焰传感器连接");
        this.appendDummyInput()
            .appendField(",采集模拟值");
        this.setOutput(true, "Number");
        this.setColour("#018997");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_FlameSensor_Analog'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['ADCGet(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_FlameSensor_Digital'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("火焰传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_FlameSensor_Digital'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 热敏传感器 ----------------------------------------
Blockly.Blocks['Perception_Thermistor_Analog'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("热敏传感器连接");
        this.appendDummyInput()
            .appendField(",采集模拟值");
        this.setOutput(true, "Number");
        this.setColour("#018997");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Thermistor_Analog'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['ADCGet(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_Thermistor_Digital'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("热敏传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Thermistor_Digital'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 光敏传感器 ----------------------------------------
Blockly.Blocks['Perception_Photoresistor_Analog'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("光敏传感器连接");
        this.appendDummyInput()
            .appendField(",采集模拟值");
        this.setOutput(true, "Number");
        this.setColour("#018997");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Photoresistor_Analog'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['ADCGet(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_Photoresistor_Digital'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("光敏传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Photoresistor_Digital'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 霍尔传感器 ----------------------------------------
Blockly.Blocks['Perception_HallSensor_Digital'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("霍尔传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_HallSensor_Digital'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 2.4G遥控器 ----------------------------------------
Blockly.Blocks['Perception_NRFRemoteRockerValue'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("2.4G遥控器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",获取摇杆值");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_NRFRemoteRockerValue'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['NRFRockerValue(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_NRFRemoteRockerDirection'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("2.4G遥控器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当摇杆");
        this.appendValueInput("GETSTATE")
            .setCheck("Number");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Perception_NRFRemoteRockerDirectionMenu'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["向前", "NRFRockerQ"],
                ["向后", "NRFRockerH"],
                ["向左", "NRFRockerZ"],
                ["向右", "NRFRockerY"],
                ["居中", "NRFRockerN"]
            ]), "BUTTONSTATE");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Perception_NRFRemoteRockerDirectionMenu'] = function() {
    var state = this.getFieldValue('BUTTONSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Perception_NRFRemoteRockerDirection'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NRFRocker = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['NRFRockerState(' + pin + ')== ' + NRFRocker, Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_NRFRemoteControl'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("2.4G遥控器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Number");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("按下时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.Blocks['Perception_NRFRemoteControlButton'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldDropdown([
                ["按键1", "NRFKey1"],
                ["按键2", "NRFKey2"],
                ["按键3", "NRFKey3"],
                ["按键4", "NRFKey4"],
                ["无按键", "NRFKeyNO"]
            ]), "BUTTONSTATE");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
    }
};
Blockly.JavaScript['Perception_NRFRemoteControlButton'] = function() {
    var state = this.getFieldValue('BUTTONSTATE');
    return [state, Blockly.JavaScript.ORDER_ATOMIC];
};
Blockly.JavaScript['Perception_NRFRemoteControl'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NRFButton = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['NRFKeyState(' + pin + ')== ' + NRFButton, Blockly.JavaScript.ORDER_NONE];
};
Blockly.Blocks['Perception_NRFRemoteControl_2'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("2.4G遥控器连接");
        this.appendDummyInput()
            .appendField(",当按键1")
            .appendField(new Blockly.FieldCheckbox("TRUE"), "NRFBUTTON1")
            .appendField("按键2")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "NRFBUTTON2")
            .appendField("按键3")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "NRFBUTTON3")
            .appendField("按键4")
            .appendField(new Blockly.FieldCheckbox("FALSE"), "NRFBUTTON4")
            .appendField("按下时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_NRFRemoteControl_2'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(block, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var NRFButton1 = block.getFieldValue('NRFBUTTON1') == 'TRUE';
    var NRFButton2 = block.getFieldValue('NRFBUTTON2') == 'TRUE';
    var NRFButton3 = block.getFieldValue('NRFBUTTON3') == 'TRUE';
    var NRFButton4 = block.getFieldValue('NRFBUTTON4') == 'TRUE';
    var NRFButtonNum = NRFButton1 | (NRFButton2 << 1) | (NRFButton3 << 2) | (NRFButton4 << 3);
    return ['NRFKeyState(' + pin + ')== ' + NRFButtonNum, Blockly.JavaScript.ORDER_NONE];
};
//---------- 震动传感器 ----------------------------------------
Blockly.Blocks['Perception_Shake'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("震动传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Shake'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 光敏传感器 ----------------------------------------
Blockly.Blocks['Perception_Photosensitive'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("光敏传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Photosensitive'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 烟雾传感器 ----------------------------------------
Blockly.Blocks['Perception_Smoke'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("烟雾传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Smoke'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 酒精传感器 ----------------------------------------
Blockly.Blocks['Perception_Alcohol'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("酒精传感器连接");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Alcohol'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 可燃气体传感器 ----------------------------------------
Blockly.Blocks['Perception_CombustibleGas'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("可燃气体传感器");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_CombustibleGas'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};
//---------- 土壤湿度传感器 ----------------------------------------
Blockly.Blocks['Perception_SoilMoisture'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("土壤湿度传感器");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField(",当");
        this.appendValueInput("GETSTATE")
            .setCheck("Boolean");
        this.appendDummyInput()
            .setAlign(Blockly.ALIGN_CENTRE)
            .appendField("感应时");
        this.setOutput(true, null);
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_SoilMoisture'] = function() {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    var state = Blockly.JavaScript.valueToCode(this, 'GETSTATE', Blockly.JavaScript.ORDER_ATOMIC);
    return ['WLINState(' + pin + ')==' + state, Blockly.JavaScript.ORDER_NONE];
};

//---------- 温湿度传感器 ----------------------------------------
Blockly.Blocks['Perception_Temperature'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("温湿度传感器连接");
        this.appendDummyInput()
            .appendField(",采集到温度值");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Temperature'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['SETUPCODE:delay_init();SETUPEND DHT11_temperature(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};

Blockly.Blocks['Perception_Humidity'] = {
    init: function() {
        this.appendValueInput("GETPIN")
            .setCheck("Number")
            .appendField("温湿度传感器连接");
        this.appendDummyInput()
            .appendField(",采集到湿度值");
        this.setOutput(true, "Number");
        this.setColour("#3db8c1");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Perception_Humidity'] = function(block) {
    var pin = Blockly.JavaScript.valueToCode(this, 'GETPIN', Blockly.JavaScript.ORDER_ATOMIC);
    return ['SETUPCODE:delay_init();SETUPEND DHT11_humidity(' + pin + ')', Blockly.JavaScript.ORDER_NONE];
};






