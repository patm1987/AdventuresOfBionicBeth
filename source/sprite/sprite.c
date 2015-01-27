
#include "sprite.h"

#include <gba_dma.h>
#include <gba_video.h>
#include <string.h> // memcpy

u16 SPGetMode() {
	return OBJ_1D_MAP | OBJ_ON;
}

void SPLoadPalettes(palette_t* paPalettes, u32 count) {
	// dmaCopy(paPalettes, SPRITE_PALETTE, sizeof(palette_t) * count);
	memcpy(SPRITE_PALETTE, paPalettes, sizeof(palette_t) * count);
}
