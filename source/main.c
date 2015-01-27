
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_sprites.h> // sprite stuff, move to sprite.h
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bg/background0.h"
#include "palette/characterdata.h"
#include "palette/palette.h"
#include "sprite/sprite.h"

// values are in the range 0 - 31
// ie: 0x00 - 0x1F
const palette_t aBackgroundPalette [] = {
	{{RGB5(0,0x1F,0x00)}}
};

const palette_t aCharacterPalette [] = {
	{{
		RGB5(0x00,0x00,0x00),
		RGB5(0x17,0x1F,0x00),
		RGB5(0x1F,0x1F,0x00),
		RGB5(0x00,0x00,0x00),
		RGB5(0x14,0x0A,0x00),
		RGB5(0x1F,0x00,0x17),
		RGB5(0x1F,0x0A,0x1F)
	}}
};

const basic_character_t aBethSprite[] = {
	{{
		0x00,0x00,0x00,0x00,
		0x00,0x11,0x22,0x00,
		0x00,0x11,0x12,0x10,
		0x01,0x34,0x43,0x10,
		0x01,0x44,0x44,0x10,
		0x00,0x43,0x34,0x00,
		0x00,0x04,0x40,0x00,
		0x00,0x05,0x60,0x00,
	}},
	{{
		0x03,0x55,0x56,0x30,
		0x30,0x55,0x56,0x03,
		0x30,0x55,0x55,0x03,
		0x05,0x55,0x55,0x50,
		0x55,0x55,0x55,0x55,
		0x00,0x30,0x03,0x00,
		0x00,0x30,0x03,0x00,
		0x03,0x30,0x03,0x30
	}}
};

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);

	SetMode(BG0GetMode() | SPGetMode());

	BG0LoadPalettes(aBackgroundPalette, sizeof(aBackgroundPalette));
	SPLoadPalettes(aCharacterPalette, sizeof(aCharacterPalette));

	memcpy(SPRITE_GFX, &aBethSprite, sizeof(aBethSprite));

	OBJATTR beth;
	beth.attr0 = OBJ_Y(0) | ATTR0_TALL | OBJ_16_COLOR;
	beth.attr1 = OBJ_X(0) | ATTR1_SIZE_8;
	beth.attr2 = OBJ_CHAR(0) | ATTR2_PALETTE(0);
	OAM[0] = beth;

	while (1) {
		VBlankIntrWait();
	}
}


