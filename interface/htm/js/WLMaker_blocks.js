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

Blockly.Blocks['otion_waliblocks8.1'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks8.1",
            "message0": "全彩LEDx3连接到OUT%1，LED1%2LED2%3LED3%4",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
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
                    "type": "field_colour",
                    "name": "COLOUR1",
                    "colour": "#ff0000"
                },
                {
                    "type": "field_colour",
                    "name": "COLOUR2",
                    "colour": "#00ff00"
                },
                {
                    "type": "field_colour",
                    "name": "COLOUR3",
                    "colour": "#0000ff"
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['otion_waliblocks8.2'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks8.2",
            "message0": "全彩LEDx3连接到OUT%1，LED%2颜色%3",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
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
                    "name": "LED",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"]
                    ]
                },
                {
                    "type": "field_colour",
                    "name": "COLOUR",
                    "colour": "#ff0000"
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['otion_waliblocks90'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks90",
            "message0": "数码管连接到U%1，数值显示%2",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"]
                    ]
                },
                {
                    "type": "input_value",
                    "name": "NUM",
                    "max": "255",
                    "min": "0"
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['otion_waliblocks9'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks9",
            "message0": "数码管连接到U%1，第%2位显示%3",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"]
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"],
                        ["4", "4"]
                    ]
                },
                {
                    "type": "input_value",
                    "name": "NUM",
                    "max": "255",
                    "min": "0"
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};

Blockly.Blocks['otion_waliblocks10'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks10",
            "message0": "数码管连接到U%1，显示%2%3%4%5",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"]
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED1",
                    "options": [
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
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED2",
                    "options": [
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
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED3",
                    "options": [
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
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED4",
                    "options": [
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
                    ]
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['otion_waliblocks11'] = {
    init: function() {
        this.jsonInit({

            "type": "otion_waliblocks11",
            "message0": "数码管连接到U%1，段%2%3%4%5",
            "args0": [{
                    "type": "field_dropdown",
                    "name": "PU",
                    "options": [
                        ["1", "1"],
                        ["2", "2"],
                        ["3", "3"]
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED1",
                    "options": [
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
                        ["全灭", "0xC9"],
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED2",
                    "options": [
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
                        ["全灭", "0xC9"],
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED3",
                    "options": [
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
                        ["全灭", "0xC9"],
                    ]
                },
                {
                    "type": "field_dropdown",
                    "name": "LED4",
                    "options": [
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
                        ["全灭", "0xC9"],
                    ]
                },
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#21c1fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};


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



/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
/************************ 控制模块 ************************/
Blockly.Blocks['control_waliblocks0'] = {
    init: function() {
        this.jsonInit({
            "message0": "等待 %1 毫秒",
            "args0": [{
                "type": "field_number",
                "name": "SHIJIAN",
                "value": 1,
                "min": 0.1,
                "max": 1000,
                //"precision": 0.1
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};
Blockly.Blocks['control_waliblocks1'] = {
    init: function() {
        this.jsonInit({
            "message0": "等待 %1 秒",
            "args0": [{
                "type": "field_number",
                "name": "SHIJIAN",
                "value": 1,
                "min": 0.1,
                "max": 1000,
                //"precision": 0.1
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};

Blockly.Blocks['control_waliblocks2'] = {
    init: function() {
        this.jsonInit({
            "message0": "重复执行 %1 %2",
            "args0": [{
                    "type": "input_dummy"
                },
                {
                    "type": "input_statement",
                    "name": "NAME"
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};

Blockly.Blocks['control_waliblocks3'] = {
    init: function() {
        this.jsonInit({

            "message0": "重复 %1 次 %2 执行 %3",
            "args0": [{
                    "type": "field_number",
                    "name": "COUNT",
                    "value": 1
                },
                {
                    "type": "input_dummy"
                },
                {
                    "type": "input_statement",
                    "name": "DO"
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "inputsInline": true,
            "tooltip": "Do some statements several times.",
            "helpUrl": "循环指定次数（默认10）"

        })
    }
};

Blockly.Blocks['controls_if'] = {
    init: function() {
        this.jsonInit({
            "type": "controls_if",
            "message0": "如果 %1 那么 %2",
            "args0": [{
                    "type": "input_value",
                    "name": "IF0",
                    "check": "Boolean"
                },
                {
                    "type": "input_statement",
                    "name": "DO0"
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": ""
        })
    }
};

Blockly.Blocks['control_waliblocks5'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks5",
            "message0": "如果 %1",
            "args0": [{
                "type": "input_value",
                "name": "IF0",
                "check": "Boolean"
            }],
            "message1": "那么 %1",
            "args1": [{
                "type": "input_statement",
                "name": "DO0"
            }],
            "message2": "否则 %1",
            "args2": [{
                "type": "input_statement",
                "name": "ELSE"
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": ""
        })
    }
};

Blockly.Blocks['control_waliblocks6'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks6",
            "message0": "一直等待直到 %1",
            "args0": [{
                "type": "input_value",
                "name": "NAME"
            }],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};

Blockly.Blocks['control_waliblocks7'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks7",
            "message0": "重复 当 %1 执行 %2",
            "args0": [{
                    "type": "input_value",
                    "name": "BOOL",
                    "check": "Boolean"
                },
                {
                    "type": "input_statement",
                    "name": "DO"
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",
            "helpUrl": "https://github.com/google/blockly/wiki/Loops#repeat"

        })
    }
};

Blockly.Blocks['control_waliblocks8'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks8",
            "message0": "for循环：初始%1=%2①判断%3%4%5，③%6=%7②执行%8",
            "args0": [{
                    "type": "input_value",
                    "name": "VAR",
                    "value": 0
                },


                {
                    "type": "input_value",
                    "name": "VAL",
                    "value": 0,
                },



                {
                    "type": "input_value",
                    "name": "A",
                    "check": "Number",

                },


                {
                    "type": "field_dropdown",
                    "name": "OP",
                    "options": [
                        ["=", "==", ],
                        ["\u2260", "!="],
                        [">", ">"],
                        ["<", "<"],
                        ["\u2265", ">="],
                        ["\u2264", "<="]
                    ]
                },


                {
                    "type": "input_value",
                    "name": "B",

                    "align": "RIGHT"
                },
                {
                    "type": "input_value",
                    "name": "VAR1",
                    "value": 0
                },

                {
                    "type": "input_value",
                    "name": "BY",
                    "check": "Number",
                    "align": "RIGHT"
                },

                {
                    "type": "input_statement",
                    "name": "DO"
                }
            ],
            "inputsInline": true,
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "tooltip": "",

            "helpUrl": "https://github.com/google/blockly/wiki/Loops#count-with"
        })
    }
};

Blockly.Blocks['control_waliblocks9'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks9",
            "message0": "%1 循环(或函数)",
            "args0": [{
                "type": "field_dropdown",
                "name": "FLOW",
                "options": [
                    ["跳出本次", "BREAK"],
                    ["跳出本次循环并继续下次", "CONTINUE"],
                    ["跳出", "RETURN"]
                ]
            }],
            "inputsInline": true,
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "helpUrl": "https://github.com/google/blockly/wiki/Loops#loop-termination-blocks",
            "TODO(#375)": "https://github.com/google/blockly-android/issues/375"
        })
    }
};

Blockly.Blocks['control_waliblocks10'] = {
    init: function() {
        this.jsonInit({

            "message0": "注释[折叠]： %1%2%3",
            "args0": [{
                    "type": "field_input",
                    "name": "COUNT",
                    "text": ""
                },
                {
                    "type": "input_dummy"
                },
                {
                    "type": "input_statement",
                    "name": "DO"
                }
            ],
            "previousStatement": null,
            "nextStatement": null,
            "colour": "#5ca3fb",
            "inputsInline": true,
            "tooltip": "Do some statements several times.",
            "helpUrl": "循环指定次数（默认10）"

        })
    }
};















/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
/************************ 运算模块 ************************/
Blockly.Blocks['wl_math_number'] = {
    init: function() {
        this.jsonInit({

            "type": "wl_math_number",
            "message0": "%1",
            "args0": [{
                "type": "field_number",
                "name": "NAME",
                "value": 0,
                "min": -127,
                "max": 128
            }],
            "output": "Number",
            "colour": "#fb7d71",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.Blocks['math_waliblocks1'] = {
    init: function() {
        this.jsonInit({

            "type": "math_waliblocks1",
            "message0": "%1 %2 %3",
            "args0": [{
                    "type": "input_value",
                    "name": "A",
                    "value": 0,
                    "min": -127,
                    "max": 128
                },
                {
                    "type": "field_dropdown",
                    "name": "OP",
                    "options": [
                        ["且", "&&"],
                        ["或", "||"]
                    ]
                },
                {
                    "type": "input_value",
                    "name": "B",
                    "value": 0,
                    "min": -127,
                    "max": 128
                }
            ],
            "inputsInline": true,
            "output": null,
            "colour": "#fb7d71",
            "tooltip": "",
            "helpUrl": "https://github.com/google/blockly/wiki/Logic#logical-operations"
        })
    }
};
Blockly.Blocks['math_waliblocks2'] = {
    init: function() {
        this.jsonInit({

            "type": "math_waliblocks2",
            "message0": "%1",
            "args0": [{
                "type": "field_dropdown",
                "name": "BOOL",
                "options": [
                    ["true", "true"],
                    ["false", "false"]
                ]
            }],
            "output": "Boolean",
            "colour": "#fb7d71",
            "tooltip": "",
            "helpUrl": "https://github.com/google/blockly/wiki/Logic#values"
        })
    }
};
Blockly.Blocks['math_waliblocks3'] = {
    init: function() {
        this.jsonInit({

            "type": "math_waliblocks3",
            "message0": "%1 %2 %3",
            "args0": [{
                    "type": "input_value",
                    "name": "A",
                    "check": "Number"
                },
                {
                    "type": "field_dropdown",
                    "name": "OP",
                    "options": [
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
                    ]
                },
                {
                    "type": "input_value",
                    "name": "B",
                    "check": "Number"
                }
            ],
            "inputsInline": true,
            "output": "Number",
            "colour": "#fb7d71"
        })
    }
};
Blockly.Blocks['math_waliblocks4'] = {
    init: function() {
        this.jsonInit({

            "type": "math_waliblocks4",
            "message0": "%1 %2 %3",
            "args0": [{
                    "type": "input_value",
                    "name": "A",
                    "check": "Number"
                },
                {
                    "type": "field_dropdown",
                    "name": "OP",
                    "options": [
                        ["=", "==", ],
                        ["\u2260", "!="],
                        [">", ">"],
                        ["<", "<"],
                        ["\u2265", ">="],
                        ["\u2264", "<="],
                    ]
                },
                {
                    "type": "input_value",
                    "name": "B",
                    "check": "Number"
                }
            ],
            "inputsInline": true,
            "output": "Boolean",
            "colour": "#fb7d71"
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


Blockly.JavaScript['otion_waliblocks8.1'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_COLOUR1 = '' + block.getFieldValue('COLOUR1');
    NUM_COLOUR1 = NUM_COLOUR1.replace('#', '0x');
    var NUM_COLOUR2 = '' + block.getFieldValue('COLOUR2');
    NUM_COLOUR2 = NUM_COLOUR2.replace('#', '0x');
    var NUM_COLOUR3 = '' + block.getFieldValue('COLOUR3');
    NUM_COLOUR3 = NUM_COLOUR3.replace('#', '0x');
    return 'SETUPCODE:RGBLED_Init(' + NUM_PU + ');SETUPEND RGBLED3_Colour3(' + NUM_PU + ',' + NUM_COLOUR1 + ',' + NUM_COLOUR2 + ',' + NUM_COLOUR3 + ');\n';

};
Blockly.JavaScript['otion_waliblocks8.2'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_LED = '' + block.getFieldValue('LED');
    var NUM_COLOUR = '' + block.getFieldValue('COLOUR');
    NUM_COLOUR = NUM_COLOUR.replace('#', '0x');

    return 'SETUPCODE:RGBLED_Init(' + NUM_PU + ');SETUPEND RGBLED3_Colour1(' + NUM_PU + ',' + NUM_LED + ',' + NUM_COLOUR + ');\n';

};
Blockly.JavaScript['otion_waliblocks90'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_NUM = Blockly.JavaScript.valueToCode(block, 'NUM', Blockly.JavaScript.ORDER_ATOMIC) || "0";

    return 'SETUPCODE:LD_Init' + NUM_PU + '();SETUPEND LD_NumSet' + NUM_PU + '(' + NUM_NUM + ');\n';
};
Blockly.JavaScript['otion_waliblocks9'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_LED = '' + block.getFieldValue('LED');
    var NUM_NUM = Blockly.JavaScript.valueToCode(block, 'NUM', Blockly.JavaScript.ORDER_ATOMIC) || "0";

    return 'SETUPCODE:LD_Init' + NUM_PU + '();SETUPEND LD_DanSet' + NUM_PU + '(' + NUM_LED + ',' + NUM_NUM + ');\n';
};
Blockly.JavaScript['otion_waliblocks10'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_LED1 = '' + block.getFieldValue('LED1');
    var NUM_LED2 = '' + block.getFieldValue('LED2');
    var NUM_LED3 = '' + block.getFieldValue('LED3');
    var NUM_LED4 = '' + block.getFieldValue('LED4');

    return 'SETUPCODE:LD_Init' + NUM_PU + '();SETUPEND LD_Set' + NUM_PU + '(' + NUM_LED1 + ',' + NUM_LED2 + ',' + NUM_LED3 + ',' + NUM_LED4 + ');\n';
};
Blockly.JavaScript['otion_waliblocks11'] = function(block) {
    var NUM_PU = '' + block.getFieldValue('PU');
    var NUM_LED1 = '' + block.getFieldValue('LED1');
    var NUM_LED2 = '' + block.getFieldValue('LED2');
    var NUM_LED3 = '' + block.getFieldValue('LED3');
    var NUM_LED4 = '' + block.getFieldValue('LED4');

    return 'SETUPCODE:LD_Init' + NUM_PU + '();SETUPEND LD_Set' + NUM_PU + '(' + NUM_LED1 + ',' + NUM_LED2 + ',' + NUM_LED3 + ',' + NUM_LED4 + ');\n';
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
Blockly.JavaScript['control_waliblocks0'] = function(block) {
    var number_shijian = block.getFieldValue('SHIJIAN');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:delay_init();SETUPEND delay_ms(" + number_shijian + ");\n";
    return code;

};
Blockly.JavaScript['control_waliblocks1'] = function(block) {
    var number_shijian = block.getFieldValue('SHIJIAN');
    // TODO: Assemble JavaScript into code variable.
    var code = "SETUPCODE:delay_init();SETUPEND delay_ms(" + number_shijian + "*1000);\n";
    return code;

};

Blockly.JavaScript['control_waliblocks2'] = function(a) {
    var b = "true" == "true",
        d = Blockly.JavaScript.statementToCode(a, "NAME"),
        d = Blockly.JavaScript.addLoopTrap(d, a.id);
    return "while (1) \n{\n" + d + "}\n"
};


Blockly.JavaScript['control_waliblocks3'] = function(block) {
    var text_count = block.getFieldValue('COUNT');
    var statements_name = Blockly.JavaScript.statementToCode(block, 'DO');
    return "for (int i__ = 0; i__ < " + text_count + "; i__ ++) \n{\n" + statements_name + "}\n";
};
Blockly.JavaScript['controls_if'] = function(block) {
    var value_if0 = Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) ? Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) : 1;
    var statements_do0 = Blockly.JavaScript.statementToCode(block, 'DO0');

    var code = 'if (' + value_if0 + ')\n{\n' + statements_do0 + '}\n';
    return code;
};
Blockly.JavaScript['control_waliblocks5'] = function(block) {
    var value_if0 = Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) ? Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) : 1;
    var statements_do0 = Blockly.JavaScript.statementToCode(block, 'DO0');
    var statements_else = Blockly.JavaScript.statementToCode(block, 'ELSE');
    var code = 'if (' + value_if0 + ')\n{\n' + statements_do0 + '}else\n{\n' + statements_else + '}\n';
    return code;
};

Blockly.JavaScript['control_waliblocks6'] = function(a) {
    var b = "UNTIL" == "UNTIL",
        c = Blockly.JavaScript.valueToCode(a, 'NAME', Blockly.JavaScript.ORDER_ATOMIC) || "1";
    b && (c = "!" + c);
    return "while (" + c + ") \n{\n" + "}\n"
};

Blockly.JavaScript['control_waliblocks7'] = function(a) {
    var b = "UNTIL" == a.getFieldValue("MODE"),
        c = Blockly.JavaScript.valueToCode(a, "BOOL", b ? Blockly.JavaScript.ORDER_LOGICAL_NOT : Blockly.JavaScript.ORDER_NONE) || "1",
        d = Blockly.JavaScript.statementToCode(a, "DO"),
        d = Blockly.JavaScript.addLoopTrap(d, a.id);
    b && (c = "!" + c);
    return "while (" + c + ")\n {\n" + d + "}\n"
};

Blockly.JavaScript['control_waliblocks8'] = function(block) {

    var variable_var = Blockly.JavaScript.valueToCode(block, 'VAR', Blockly.JavaScript.ORDER_ATOMIC);
    var value_val = Blockly.JavaScript.valueToCode(block, 'VAL', Blockly.JavaScript.ORDER_ATOMIC);
    var value_a = Blockly.JavaScript.valueToCode(block, 'A', Blockly.JavaScript.ORDER_ATOMIC);
    var dropdown_op = block.getFieldValue('OP');
    var value_b = Blockly.JavaScript.valueToCode(block, 'B', Blockly.JavaScript.ORDER_ATOMIC);
    var variable_var1 = Blockly.JavaScript.valueToCode(block, 'VAR1', Blockly.JavaScript.ORDER_ATOMIC);
    var value_by = Blockly.JavaScript.valueToCode(block, 'BY', Blockly.JavaScript.ORDER_ATOMIC);
    var statements_do = Blockly.JavaScript.statementToCode(block, 'DO');
    // TODO: Assemble JavaScript into code variable.
    if (variable_var == "0") {
        variable_var = "";
        value_val = "";
    } else {
        variable_var = variable_var + "=";
    }
    if (value_a == "0") {
        value_a = "";
        dropdown_op = "";
        value_b = "";
    }

    if (variable_var1 == "0") {
        variable_var1 = "";
        value_by = "";
    } else {
        variable_var1 = variable_var1 + "=";
    }
    var code = "for(" + variable_var + value_val + ";" + value_a + dropdown_op + value_b + ";" + variable_var1 + value_by + ")\n {\n" + statements_do + "}\n";
    return code;
};

Blockly.JavaScript['control_waliblocks9'] = function(a) {
    switch (a.getFieldValue("FLOW")) {
        case "BREAK":
            return "break;\n";
        case "CONTINUE":
            return "continue;\n"
        case "RETURN":
            return "return;\n"
    }
    throw "Unknown flow statement.";
};
Blockly.JavaScript['control_waliblocks10'] = function(block) {
    var text_count = block.getFieldValue('COUNT');
    var statements_name = Blockly.JavaScript.statementToCode(block, 'DO');
    return "/*" + text_count + "*/\n{\n" + statements_name + "}\n";
};


Blockly.JavaScript['wl_math_number'] = function(block) {
    var number_name = block.getFieldValue('NAME');

    return [number_name, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_waliblocks1'] = function(block) {
    var number_a = Blockly.JavaScript.valueToCode(block, 'A',
        Blockly.JavaScript.ORDER_NONE) || '0';
    var dropdown_op = block.getFieldValue('OP');
    var number_b = Blockly.JavaScript.valueToCode(block, 'B',
        Blockly.JavaScript.ORDER_NONE) || '0';
    // TODO: Assemble JavaScript into code variable.
    var code = number_a + dropdown_op + number_b;
    // TODO: Change ORDER_NONE to the correct strength.
    return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_waliblocks2'] = function(block) {
    var dropdown_name = block.getFieldValue('BOOL');

    return [dropdown_name, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_waliblocks3'] = function(block) {
    var number_a = Blockly.JavaScript.valueToCode(block, 'A',
        Blockly.JavaScript.ORDER_NONE) || '0';
    var dropdown_op = block.getFieldValue('OP');
    var number_b = Blockly.JavaScript.valueToCode(block, 'B',
        Blockly.JavaScript.ORDER_NONE) || '0';
    // TODO: Assemble JavaScript into code variable.
    var code = "(" + number_a + dropdown_op + number_b + ")";
    // TODO: Change ORDER_NONE to the correct strength.
    return [code, Blockly.JavaScript.ORDER_NONE];
};
Blockly.JavaScript['math_waliblocks4'] = function(block) {
    var number_a = Blockly.JavaScript.valueToCode(block, 'A',
        Blockly.JavaScript.ORDER_NONE) || '0';
    var dropdown_op = block.getFieldValue('OP');
    var number_b = Blockly.JavaScript.valueToCode(block, 'B',
        Blockly.JavaScript.ORDER_NONE) || '0';
    // TODO: Assemble JavaScript into code variable.
    var code = number_a + dropdown_op + number_b;
    // TODO: Change ORDER_NONE to the correct strength.
    return [code, Blockly.JavaScript.ORDER_NONE];
};