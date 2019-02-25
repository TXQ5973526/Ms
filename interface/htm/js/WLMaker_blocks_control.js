'use strict';

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog');
goog.require('goog.ui.Slider');

//---------- 数值 ----------------------------------------
Blockly.Blocks['Control_Num'] = {
    init: function() {
        this.appendDummyInput()
            .appendField(new Blockly.FieldNumber(0, -32768, 65536), "NUM");
        this.setOutput(true, null);
        this.setColour("#948aec");
        this.setTooltip("");
        this.setHelpUrl("");
    }
};
Blockly.JavaScript['Control_Num'] = function(block) {
    var num = this.getFieldValue('NUM');
    return [num, Blockly.JavaScript.ORDER_ATOMIC];
};

Blockly.Blocks['controls_if'] = {
    init: function() {
        this.setHelpUrl(Blockly.Msg.CONTROLS_IF_HELPURL);
        this.setColour("#948aec");
        this.appendValueInput("IF0").setCheck("Boolean").appendField(Blockly.Msg.CONTROLS_IF_MSG_IF);
        this.appendStatementInput("DO0").appendField(Blockly.Msg.CONTROLS_IF_MSG_THEN);
        this.setPreviousStatement(!0);
        this.setNextStatement(!0);
        this.setMutator(new Blockly.Mutator(["controls_if_elseif", "controls_if_else"]));
        var a = this;
        this.setTooltip(function() {
            if (a.elseifCount_ || a.elseCount_) {
                if (!a.elseifCount_ && a.elseCount_) return Blockly.Msg.CONTROLS_IF_TOOLTIP_2;
                if (a.elseifCount_ && !a.elseCount_) return Blockly.Msg.CONTROLS_IF_TOOLTIP_3;
                if (a.elseifCount_ && a.elseCount_) return Blockly.Msg.CONTROLS_IF_TOOLTIP_4
            } else return Blockly.Msg.CONTROLS_IF_TOOLTIP_1;
            return ""
        });
        this.elseCount_ = this.elseifCount_ = 0
    },
    mutationToDom: function() {
        if (!this.elseifCount_ && !this.elseCount_) return null;
        var a = document.createElement("mutation");
        this.elseifCount_ && a.setAttribute("elseif", this.elseifCount_);
        this.elseCount_ && a.setAttribute("else", 1);
        return a
    },
    domToMutation: function(a) {
        this.elseifCount_ = parseInt(a.getAttribute("elseif"), 10) || 0;
        this.elseCount_ = parseInt(a.getAttribute("else"), 10) || 0;
        this.updateShape_()
    },
    decompose: function(a) {
        var b = a.newBlock("controls_if_if");
        b.initSvg();
        for (var c = b.nextConnection,
                e = 1; e <= this.elseifCount_; e++) {
            var d = a.newBlock("controls_if_elseif");
            d.initSvg();
            c.connect(d.previousConnection);
            c = d.nextConnection
        }
        this.elseCount_ && (a = a.newBlock("controls_if_else"), a.initSvg(), c.connect(a.previousConnection));
        return b
    },
    compose: function(a) {
        var b = a.nextConnection.targetBlock();
        this.elseCount_ = this.elseifCount_ = 0;
        a = [null];
        for (var c = [null], e = null; b;) {
            switch (b.type) {
                case "controls_if_elseif":
                    this.elseifCount_++;
                    a.push(b.valueConnection_);
                    c.push(b.statementConnection_);
                    break;
                case "controls_if_else":
                    this.elseCount_++;
                    e = b.statementConnection_;
                    break;
                default:
                    throw "Unknown block type.";
            }
            b = b.nextConnection && b.nextConnection.targetBlock()
        }
        this.updateShape_();
        for (b = 1; b <= this.elseifCount_; b++) Blockly.Mutator.reconnect(a[b], this, "IF" + b),
            Blockly.Mutator.reconnect(c[b], this, "DO" + b);
        Blockly.Mutator.reconnect(e, this, "ELSE")
    },
    saveConnections: function(a) {
        a = a.nextConnection.targetBlock();
        for (var b = 1; a;) {
            switch (a.type) {
                case "controls_if_elseif":
                    var c = this.getInput("IF" + b),
                        e = this.getInput("DO" + b);
                    a.valueConnection_ = c && c.connection.targetConnection;
                    a.statementConnection_ = e && e.connection.targetConnection;
                    b++;
                    break;
                case "controls_if_else":
                    e = this.getInput("ELSE");
                    a.statementConnection_ = e && e.connection.targetConnection;
                    break;
                default:
                    throw "Unknown block type.";
            }
            a = a.nextConnection && a.nextConnection.targetBlock()
        }
    },
    updateShape_: function() {
        this.getInput("ELSE") && this.removeInput("ELSE");
        for (var a = 1; this.getInput("IF" + a);) this.removeInput("IF" + a),
            this.removeInput("DO" + a),
            a++;
        for (a = 1; a <= this.elseifCount_; a++) this.appendValueInput("IF" + a).setCheck("Boolean").appendField(Blockly.Msg.CONTROLS_IF_MSG_ELSEIF),
            this.appendStatementInput("DO" + a).appendField(Blockly.Msg.CONTROLS_IF_MSG_THEN);
        this.elseCount_ && this.appendStatementInput("ELSE").appendField(Blockly.Msg.CONTROLS_IF_MSG_ELSE)
    }
};
Blockly.Blocks['controls_if_if'] = {
    init: function() {
        this.setColour("#948aec");
        this.appendDummyInput().appendField(Blockly.Msg.CONTROLS_IF_IF_TITLE_IF);
        this.setNextStatement(!0);
        this.setTooltip(Blockly.Msg.CONTROLS_IF_IF_TOOLTIP);
        this.contextMenu = !1
    }
};
Blockly.Blocks['controls_if_elseif'] = {
    init: function() {
        this.setColour("#948aec");
        this.appendDummyInput().appendField(Blockly.Msg.CONTROLS_IF_ELSEIF_TITLE_ELSEIF);
        this.setPreviousStatement(!0);
        this.setNextStatement(!0);
        this.setTooltip(Blockly.Msg.CONTROLS_IF_ELSEIF_TOOLTIP);
        this.contextMenu = !1
    }
};
Blockly.Blocks['controls_if_else'] = {
    init: function() {
        this.setColour("#948aec");
        this.appendDummyInput().appendField(Blockly.Msg.CONTROLS_IF_ELSE_TITLE_ELSE);
        this.setPreviousStatement(!0);
        this.setTooltip(Blockly.Msg.CONTROLS_IF_ELSE_TOOLTIP);
        this.contextMenu = !1
    }
};
Blockly.JavaScript['controls_if'] = function(a) {
    for (var b = 0, c = Blockly.JavaScript.valueToCode(a, "IF" + b, Blockly.JavaScript.ORDER_NONE) || "0", d = Blockly.JavaScript.statementToCode(a, "DO" + b), e = "if (" + c + "){\n" + d + "}", b = 1; b <= a.elseifCount_; b++) c = Blockly.JavaScript.valueToCode(a, "IF" + b, Blockly.JavaScript.ORDER_NONE) || "0", d = Blockly.JavaScript.statementToCode(a, "DO" + b), e += "else if (" + c + "){\n" + d + "}";
    a.elseCount_ && (d = Blockly.JavaScript.statementToCode(a, "ELSE"), e += "else{\n" + d + "}");
    return e + "\n"
};





// Blockly.Blocks['controls_if'] = {
//     init: function() {
//         this.jsonInit({
//             "type": "controls_if",
//             "message0": "如果 %1 那么 %2",
//             "args0": [{
//                     "type": "input_value",
//                     "name": "IF0",
//                     "check": "Boolean"
//                 },
//                 {
//                     "type": "input_statement",
//                     "name": "DO0"
//                 }
//             ],
//             "previousStatement": null,
//             "nextStatement": null,
//             "colour": "#948aec",
//             "tooltip": ""
//         })
//     }
// };
// Blockly.JavaScript['controls_if'] = function(block) {
//     var value_if0 = Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) ? Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) : 1;
//     var statements_do0 = Blockly.JavaScript.statementToCode(block, 'DO0');

//     var code = 'if (' + value_if0 + ')\n{\n' + statements_do0 + '}\n';
//     return code;
// };
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
            "colour": "#948aec",
            "tooltip": "",
            "helpUrl": ""

        })
    }
};
Blockly.JavaScript['control_waliblocks2'] = function(a) {
    var b = "true" == "true",
        d = Blockly.JavaScript.statementToCode(a, "NAME"),
        d = Blockly.JavaScript.addLoopTrap(d, a.id);
    return "while (1) \n{\n" + d + "}\n"
};
Blockly.Blocks['Control_LoopNum'] = {
  init: function() {
    this.appendValueInput("NUM")
        .setCheck(null)
        .appendField("重复");
    this.appendDummyInput()
        .appendField("次");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour('#948aec');
 this.setTooltip("");
 this.setHelpUrl("");
  }
};
Blockly.JavaScript['Control_LoopNum'] = function(block) {
    var text_count = block.getFieldValue('NUM');
    var statements_name = Blockly.JavaScript.statementToCode(block, 'DO');
    return "for (int i__ = 0; i__ < " + text_count + "; i__ ++) \n{\n" + statements_name + "}\n";
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
            "colour": "#948aec",
            "tooltip": ""
        })
    }
};
Blockly.JavaScript['control_waliblocks5'] = function(block) {
    var value_if0 = Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) ? Blockly.JavaScript.valueToCode(block, 'IF0', Blockly.JavaScript.ORDER_ATOMIC) : 1;
    var statements_do0 = Blockly.JavaScript.statementToCode(block, 'DO0');
    var statements_else = Blockly.JavaScript.statementToCode(block, 'ELSE');
    var code = 'if (' + value_if0 + ')\n{\n' + statements_do0 + '}else\n{\n' + statements_else + '}\n';
    return code;
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
            "colour": "#948aec",
            "tooltip": "",
            "helpUrl": ""
        })
    }
};
Blockly.JavaScript['control_waliblocks6'] = function(a) {
    var b = "UNTIL" == "UNTIL",
        c = Blockly.JavaScript.valueToCode(a, 'NAME', Blockly.JavaScript.ORDER_ATOMIC) || "1";
    b && (c = "!" + c);
    return "while (" + c + ") \n{\n" + "}\n"
};
Blockly.Blocks['control_waliblocks7'] = {
    init: function() {
        this.jsonInit({

            "type": "control_waliblocks7",
            "message0": "当 %1 重复 %2",
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
            "colour": "#948aec",
            "tooltip": "",
            "helpUrl": "https://github.com/google/blockly/wiki/Loops#repeat"

        })
    }
};
Blockly.JavaScript['control_waliblocks7'] = function(a) {
    var b = "UNTIL" == a.getFieldValue("MODE"),
        c = Blockly.JavaScript.valueToCode(a, "BOOL", b ? Blockly.JavaScript.ORDER_LOGICAL_NOT : Blockly.JavaScript.ORDER_NONE) || "1",
        d = Blockly.JavaScript.statementToCode(a, "DO"),
        d = Blockly.JavaScript.addLoopTrap(d, a.id);
    b && (c = "!" + c);
    return "while (" + c + ")\n {\n" + d + "}\n"
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
            "colour": "#948aec",
            "tooltip": "",

            "helpUrl": "https://github.com/google/blockly/wiki/Loops#count-with"
        })
    }
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
            "colour": "#948aec",
            "helpUrl": "https://github.com/google/blockly/wiki/Loops#loop-termination-blocks",
            "TODO(#375)": "https://github.com/google/blockly-android/issues/375"
        })
    }
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
            "colour": "#948aec",
            "inputsInline": true,
            "tooltip": "Do some statements several times.",
            "helpUrl": "循环指定次数（默认10）"

        })
    }
};
Blockly.JavaScript['control_waliblocks10'] = function(block) {
    var text_count = block.getFieldValue('COUNT');
    var statements_name = Blockly.JavaScript.statementToCode(block, 'DO');
    return "/*" + text_count + "*/\n{\n" + statements_name + "}\n";
};

























// //---------- 延时_秒 ----------------------------------------
// Blockly.Blocks['Control_DelayS'] = {
//     init: function() {
//         this.appendValueInput("NUM")
//             .setCheck(null)
//             .appendField("等待");
//         this.appendDummyInput()
//             .appendField("秒");
//         this.setPreviousStatement(true, null);
//         this.setNextStatement(true, null);
//         this.setColour("#948aec");
//         this.setTooltip("");
//         this.setHelpUrl("");
//     }
// };
// Blockly.Blocks['Control_DelayNum'] = {
//     init: function() {
//         this.appendDummyInput()
//             .appendField(new Blockly.FieldNumber(1, 0, 10000), "NUM");
//         this.setOutput(true, null);
//         this.setColour("#948aec");
//         this.setTooltip("");
//         this.setHelpUrl("");
//     }
// };
// Blockly.JavaScript['Control_DelayNum'] = function(block) {
//     var num = this.getFieldValue('NUM');
//     return [num, Blockly.JavaScript.ORDER_ATOMIC];
// };
// Blockly.JavaScript['Control_DelayS'] = function(block) {
//     var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
//     return "delay_s(" + value_num + ");\n";
// };
// //---------- 延时_毫秒 ----------------------------------------
// Blockly.Blocks['Control_DelayMs'] = {
//     init: function() {
//         this.appendValueInput("NUM")
//             .setCheck(null)
//             .appendField("等待");
//         this.appendDummyInput()
//             .appendField("毫秒");
//         this.setPreviousStatement(true, null);
//         this.setNextStatement(true, null);
//         this.setColour("#948aec");
//         this.setTooltip("");
//         this.setHelpUrl("");
//     }
// };
// Blockly.JavaScript['Control_DelayMs'] = function(block) {
//     var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
//     return "delay_ms(" + value_num + ");\n";
// };
// //---------- 延时_微妙 ----------------------------------------
// Blockly.Blocks['Control_DelayUs'] = {
//     init: function() {
//         this.appendValueInput("NUM")
//             .setCheck(null)
//             .appendField("等待");
//         this.appendDummyInput()
//             .appendField("微秒");
//         this.setPreviousStatement(true, null);
//         this.setNextStatement(true, null);
//         this.setColour("#948aec");
//         this.setTooltip("");
//         this.setHelpUrl("");
//     }
// };
// Blockly.JavaScript['Control_DelayUs'] = function(block) {
//     var value_num = Blockly.JavaScript.valueToCode(this, 'NUM', Blockly.JavaScript.ORDER_ATOMIC);
//     return "delay_us(" + value_num + ");\n";;
// };