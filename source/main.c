
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

#include "bg/background0.h"
#include "palette/palette.h"
#include "sprite/sprite.h"

// values are in the range 0 - 31
// ie: 0x00 - 0x1F
palette_t aPalettes [] = {
	RGB5(0,0x1F,0x00)
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
	
	BG0LoadPalettes(aPalettes, sizeof(aPalettes));

	while (1) {
		VBlankIntrWait();
	}
}


