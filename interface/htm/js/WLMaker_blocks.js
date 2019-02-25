'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

/**************************** 输入模块 *****************************/
Blockly.Blocks['perception_waliblocks8_1'] = {
    init: function() {
        this.jsonInit({

            "type": "perception_waliblocks8_1",
            "message0": "温湿度连到 IN %1 , 当采集到温度值",
            "args0": [{
                "type": "field_dropdown",
                "name": "IO_IN",
                "options": [
                    ["1", "1"],
                    ["2", "2"],
                    ["3", "3"],
                    ["4", "4"],
                    ["5", "5"],
                    ["6", "6"],
                    ["7", "7"],
                    ["8", "8"]
                ]
            }],
            "output": "Number",
            "colour": "#08ad9d",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['perception_waliblocks8_2'] = {
    init: function() {
        this.jsonInit({

            "type": "perception_waliblocks8_2",
            "message0": "温湿度连到 IN %1 , 当采集到湿度值",
            "args0": [{
                "type": "field_dropdown",
                "name": "IO_IN",
                "options": [
                    ["1", "1"],
                    ["2", "2"],
                    ["3", "3"],
                    ["4", "4"],
                    ["5", "5"],
                    ["6", "6"],
                    ["7", "7"],
                    ["8", "8"]
                ]
            }],
            "output": "Number",
            "colour": "#08ad9d",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['perception_waliblocksEnd'] = {
    init: function() {
        this.jsonInit({

            "type": "perception_waliblocksEnd",
            "message0": "自定义输入 %1",
            "args0": [{
                "type": "field_input",
                "name": "COUNT",
                "text": ""
            }],
            "output": "Boolean",
            "colour": "#00ceba",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};


/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/
/**************************** 输出模块 *****************************/



Blockly.Blocks['otion_waliblocksOLED_1'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_1",
            "message0": "OLED连接到OUT %1,列坐标 %2 行坐标 %3 显示第 %4 个汉字",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PINOUT",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"],
                        ["5", "5"],
                        ["6", "6"],
                        ["7", "7"],
                        ["8", "8"]
                    ]
                },
                {
                    "type": "field_number",
                    "name": "LIE",
                    "value": 0,
                    "min": 0,
                    "max": 111,
                    "precision": 1
                },
                {
                    "type": "field_number",
                    "name": "HANG",
                    "value": 0,
                    "min": 0,
                    "max": 7,
                    "precision": 1
                },
                {
                    "type": "field_number",
                    "name": "HANZI",
                    "value": 0,
                    "min": 0,
                    "max": 100,
                    "precision": 1
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};

Blockly.Blocks['otion_waliblocksOLED_2'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_2",
            "message0": "OLED连接到OUT %1,列坐标 %2 行坐标 %3 , %4 字符 %5 显示字符串 %6",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PINOUT",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"],
                        ["5", "5"],
                        ["6", "6"],
                        ["7", "7"],
                        ["8", "8"]
                    ]
                },
                {
                    "type": "field_number",
                    "name": "LIE",
                    "value": 0,
                    "min": 0,
                    "max": 121,
                    "precision": 1
                },
                {
                    "type": "field_number",
                    "name": "HANG",
                    "value": 0,
                    "min": 0,
                    "max": 7,
                    "precision": 1
                },
                {
                    "type": "field_dropdown",
                    "name": "SIZE",
                    "options": [
                        ["大", "16"],
                        ["小", "12"]
                    ]
                },
                {
                    "type": "input_dummy"
                },
                {
                    "type": "field_input",
                    "name": "ZIFU",
                    "text": ""
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};

Blockly.Blocks['otion_waliblocksOLED_3'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_3",
            "message0": "OLED连接到OUT %1,列坐标 %2 行坐标 %3, %4字号显示 %5位，数值 %6",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PINOUT",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"],
                        ["5", "5"],
                        ["6", "6"],
                        ["7", "7"],
                        ["8", "8"]
                    ]
                },
                {
                    "type": "field_number",
                    "name": "LIE",
                    "value": 0,
                    "min": 0,
                    "max": 121,
                    "precision": 1
                },
                {
                    "type": "field_number",
                    "name": "HANG",
                    "value": 0,
                    "min": 0,
                    "max": 7,
                    "precision": 1
                },
                {
                    "type": "field_dropdown",
                    "name": "SIZE",
                    "options": [
                        ["大", "16"],
                        ["小", "12"]
                    ]
                },
                {
                    "type": "field_number",
                    "name": "WEI",
                    "value": 3,
                    "min": 0,
                    "max": 10,
                    "precision": 1
                },
                {
                    "type": "input_value",
                    "name": "NAME",
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};
Blockly.Blocks['otion_waliblocksOLED_4'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_4",
            "message0": "OLED连接到OUT %1,列坐标 %2 行坐标 %3, %4字号显示字符%5",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PINOUT",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"],
                        ["5", "5"],
                        ["6", "6"],
                        ["7", "7"],
                        ["8", "8"]
                    ]
                },
                {
                    "type": "field_number",
                    "name": "LIE",
                    "value": 0,
                    "min": 0,
                    "max": 121,
                    "precision": 1
                },
                {
                    "type": "field_number",
                    "name": "HANG",
                    "value": 0,
                    "min": 0,
                    "max": 7,
                    "precision": 1
                },
                {
                    "type": "field_dropdown",
                    "name": "SIZE",
                    "options": [
                        ["大", "16"],
                        ["小", "12"]
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "ZIFU",
                    "options": [
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

                    ]
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};

Blockly.Blocks['otion_waliblocksOLED_5'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_1",
            "message0": "OLED连接到OUT %1,清屏",
            "args0": [{
                "type": "field_dropdown",
                "name": "PINOUT",
                "options": [
                    ["1", "1"],
                    ["2", "2"],
                    ["3", "3"],
                    ["4", "4"],
                    ["5", "5"],
                    ["6", "6"],
                    ["7", "7"],
                    ["8", "8"]
                ]
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};
Blockly.Blocks['otion_waliblocksOLED_6'] = {
    init: function() {
        this.jsonInit({
            "type": "otion_waliblocksOLED_1",
            "message0": "OLED连接到OUT %1,显示瓦力工厂Logo",
            "args0": [{
                "type": "field_dropdown",
                "name": "PINOUT",
                "options": [
                    ["1", "1"],
                    ["2", "2"],
                    ["3", "3"],
                    ["4", "4"],
                    ["5", "5"],
                    ["6", "6"],
                    ["7", "7"],
                    ["8", "8"]
                ]
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};
Blockly.Blocks['otion_waliblocksNEC_0'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocksNEC_0",
            "message0": "蓝牙音频模块连接到OUT %1 执行 %2",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "CHAJIAO",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"],
                        ["5", "5"],
                        ["6", "6"],
                        ["7", "7"],
                        ["8", "8"]
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "XUANXIANG",
                    "options": [
                        ["模式选择", "NEC_Mode"],
                        ["停止/播放", "NEC_Pause_Play"],
                        ["静音", "NEC_Silent"],
                        ["上一首", "NEC_Prev"],
                        ["下一首", "NEC_Next"],
                        ["增大音量", "NEC_Increase"],
                        ["减小音量", "NEC_Decrease"],
                    ]
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['otion_waliblocksEnd'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocksEnd",
            "message0": "自定义输出 %1",
            "args0": [{
                "type": "field_input",
                "name": "COUNT",
                "text": ""
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};




Blockly.JavaScript['SetHighLowevel'] = function() {
    //var dropdown_stat = Blockly.Arduino.valueToCode(this, 'STAT', Blockly.Arduino.ORDER_ATOMIC);
    //var var1 = Blockly.Generator.prototype.valueToCode(this, 'STAT', Blockly.JavaScript.ORDER_ATOMIC);
    var var1 = Blockly.JavaScript.valueToCode(this, 'STAT', Blockly.JavaScript.ORDER_ATOMIC);

    return var1;
};





Blockly.JavaScript['start_waliblocks'] = function(block) {
    // TODO: Assemble JavaScript into code variable.
    return '#include "WaLi.h"\n';
};

Blockly.JavaScript['perception_waliblocks1'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocks2'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['perception_waliblocks3'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['perception_waliblocks4'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:IRCS' + number_chajiao + '_Init();SETUPEND IRCU' + number_chajiao + '== IR_Button' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
    //return ['没弄呢' + number_chajiao, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_irremotecontrol_2'] = function(block) {
    var number_chajiao = block.getFieldValue('IOCHOOSE');
    var IRButton1 = (block.getFieldValue('IRBUTTON1') == 'TRUE') ? 1 : 0;
    var IRButton2 = (block.getFieldValue('IRBUTTON2') == 'TRUE') ? 1 : 0;
    var IRButton3 = (block.getFieldValue('IRBUTTON3') == 'TRUE') ? 1 : 0;
    var IRButton4 = (block.getFieldValue('IRBUTTON4') == 'TRUE') ? 1 : 0;
    var IRButton5 = (block.getFieldValue('IRBUTTON5') == 'TRUE') ? 1 : 0;
    var IRButton6 = (block.getFieldValue('IRBUTTON6') == 'TRUE') ? 1 : 0;
    var IRButtonNum = (IRButton1 << 7) | (IRButton2 << 6) | (IRButton3 << 5) | (IRButton4 << 4) | (IRButton5 << 3) | (IRButton6 << 2);
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:IRCS' + number_chajiao + '_Init();SETUPEND IRCU' + number_chajiao + '== ' + IRButtonNum, Blockly.JavaScript.ORDER_NONE];
    //return ['没弄呢' + number_chajiao, Blockly.JavaScript.ORDER_NONE];
};



Blockly.JavaScript['perception_waliblocks5_0'] = function(block) {
    var number_in = block.getFieldValue('IO_IN');
    return ['SETUPCODE:Adc_Init(INPUT' + number_in + '_1);SETUPEND GetAdc(INPUT' + number_in + '_1)', Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['perception_waliblocks6_0'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocks5_1'] = function(block) {
    var number_in = block.getFieldValue('IO_IN');
    return ['SETUPCODE:Adc_Init(INPUT' + number_in + '_1);SETUPEND GetAdc(INPUT' + number_in + '_1)', Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocks6_4'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
}; //可燃气体
Blockly.JavaScript['perception_waliblocks6_6'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
}; //土壤湿度
Blockly.JavaScript['perception_waliblocks6_1'] = function(block) {
    var number_chajiao = block.getFieldValue('CHAJIAO');
    var dropdown_zhuangtai = block.getFieldValue('ZHUANGAI');
    // TODO: Assemble JavaScript into code variable.
    return ['SETUPCODE:WLIN1_Init(INPUT' + number_chajiao + '_1);SETUPEND WLIN' + number_chajiao + '_1_State==' + dropdown_zhuangtai, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocks8_1'] = function(block) {
    var number_in = block.getFieldValue('IO_IN');
    return ['SETUPCODE:DHT11_Init(INPUT' + number_in + ');SETUPEND DHT11_temperature(INPUT' + number_in + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocks8_2'] = function(block) {
    var number_in = block.getFieldValue('IO_IN');
    return ['SETUPCODE:DHT11_Init(INPUT' + number_in + ');SETUPEND DHT11_humidity(INPUT' + number_in + ')', Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['perception_waliblocksEnd'] = function(block) {
    var text_count = block.getFieldValue('COUNT');
    return [text_count, Blockly.JavaScript.ORDER_NONE];
};













//-------------------------------------------------

Blockly.JavaScript['otion_waliblocks5'] = function(block) {
    var number_chajiao = '' + block.getFieldValue('PU');
    return 'SETUPCODE:NRFCS' + number_chajiao + '_Init();SETUPEND NRFRC' + number_chajiao + 'Motor();\n';
};

Blockly.JavaScript['otion_waliblocks6'] = function(block) {
    var NUM_XY = '' + block.getFieldValue('XY');
    var NUM_Motor = '' + block.getFieldValue('Motor');
    var NUM_DIR = '' + block.getFieldValue('DIR');
    return 'NRFRCMotorSet(' + NUM_XY + ',Motor' + NUM_Motor + ',' + NUM_DIR + ');\n';
};



Blockly.JavaScript['otion_waliblocksOLED_1'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    var number_lie = block.getFieldValue('LIE');
    var number_hang = block.getFieldValue('HANG');
    var number_hanzi = block.getFieldValue('HANZI');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_PinShowCHinese(OUTPUT" + number_chajiao + "," + number_lie + "," + number_hang + "," + number_hanzi + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksOLED_2'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    var number_lie = block.getFieldValue('LIE');
    var number_hang = block.getFieldValue('HANG');
    var number_zifu = block.getFieldValue('ZIFU');
    var number_size = block.getFieldValue('SIZE');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_PinShowString(OUTPUT" + number_chajiao + "," + number_lie + "," + number_hang + ",\"" + number_zifu + "\"," + number_size + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksOLED_3'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    var number_lie = block.getFieldValue('LIE');
    var number_hang = block.getFieldValue('HANG');
    var number_num = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC) || "100";
    var number_wei = block.getFieldValue('WEI');
    var number_size = block.getFieldValue('SIZE');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_PinShowNum(OUTPUT" + number_chajiao + "," + number_lie + "," + number_hang + "," + number_num + "," + number_wei + "," + number_size + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksOLED_4'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    var number_lie = block.getFieldValue('LIE');
    var number_hang = block.getFieldValue('HANG');
    var number_size = block.getFieldValue('SIZE');
    var number_zifu = block.getFieldValue('ZIFU');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_PinShowChar(OUTPUT" + number_chajiao + "," + number_lie + "," + number_hang + "," + number_zifu + "," + number_size + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksOLED_5'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_PinClear(OUTPUT" + number_chajiao + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksOLED_6'] = function(block) {
    var number_chajiao = block.getFieldValue('PINOUT');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:OLED_Init(OUTPUT" + number_chajiao + ");SETUPEND OLED_ShowPicture(OUTPUT" + number_chajiao + ");\n";
    return code;
};
Blockly.JavaScript['otion_waliblocksNEC_0'] = function(block) {
    var number_chajiao = '' + block.getFieldValue('CHAJIAO');
    // TODO: Assemble JavaScript into code variable.
    var dropdown_xuanxiang = block.getFieldValue('XUANXIANG');
    return 'SETUPCODE:delay_init();\nNEC_Init(OUTPUT' + number_chajiao + '_1);SETUPEND NEC_Send_Command(OUTPUT' + number_chajiao + '_1,' + dropdown_xuanxiang + ');\n';
};
Blockly.JavaScript['otion_waliblocksEnd'] = function(block) {
    var text_count = block.getFieldValue('COUNT');
    return text_count + ';\n';
};
/***************************** 控制 *********************************/
