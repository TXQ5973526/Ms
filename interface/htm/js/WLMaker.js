'use strict';

goog.provide('IBlockly.FieldTextInput');
goog.provide('IBlockly.FieldColour');

goog.require('Blockly.Blocks');
goog.require('goog.ui.Dialog')
goog.require('goog.ui.Slider');

IBlockly.FieldTextInput = function(text) {
	IBlockly.FieldTextInput.superClass_.constructor.call(this, text);
};
goog.inherits(IBlockly.FieldTextInput, Blockly.FieldTextInput);

IBlockly.FieldTextInput.prototype.showEditor_ = function(opt_quietInput) {
	return;
}

IBlockly.FieldTextInput.prototype.setValue = function(text) {
	if (text === null) {
    return;  // No change if null.
}
if (this.sourceBlock_) {
	var validated = this.callValidator(text);
    // If the new text is invalid, validation returns null.
    // In this case we still want to display the illegal result.
    if (validated !== null) {
    	text = validated;
    }
}
Blockly.FieldTextInput.prototype.setValue.call(this, text);
};

IBlockly.FieldColour = function(colour) {
	IBlockly.FieldTextInput.superClass_.constructor.call(this, colour);
//	this.size_ = new goog.math.Size(0, 254);
//	   this.borderRect_ = Blockly.createSvgElement('rect',
//    {'rx': 64,
//     'ry':24,
//     'x': -Blockly.BlockSvg.SEP_SPACE_X / 2,
//     'y': 20,
//     'height': 126}, this.fieldGroup_, this.sourceBlock_.workspace);
};
goog.inherits(IBlockly.FieldColour, Blockly.FieldColour);

IBlockly.FieldColour.prototype.showEditor_ = function() {
	return;
}

IBlockly.FieldColour.prototype.setValue = function(colour) {
	if (colour === null) {
    return;  // No change if null.
}
Blockly.FieldColour.prototype.setValue.call(this, colour);
};
