
#include "background0.h"

#include <gba_dma.h>
#include <gba_video.h>
#include <string.h> // memcpy

u16 BG0GetMode() {
	return MODE_0 | BG0_ON;
}

void BG0LoadPalettes(palette_t* paPalettes, u32 count) {
	// dmaCopy(paPalettes, BG_PALETTE, sizeof(palette_t) * count);
	memcpy(BG_PALETTE, paPalettes, sizeof(palette_t) * count);
}
