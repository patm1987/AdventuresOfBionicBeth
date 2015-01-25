
#include "sprite.h"

#include <gba_video.h>

u16 SPGetMode() {
	return OBJ_1D_MAP;
}

void SPLoadPalettes(palette_t* paPalettes, u32 count) {
	dmaCopy(paPalettes, SPRITE_PALETTE, sizeof(palette_t) * count);
}
