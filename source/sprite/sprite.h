
#ifndef __SPRITE_H_
#define __SPRITE_H_

#include <gba_types.h>

#include "palette/palette.h"

u16 SPGetMode();
void SPLoadPalettes(const palette_t* paPalettes, u32 count);

#endif//__SPRITE_H_
