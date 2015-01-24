
#ifndef __BACKGROUND0_H_
#define __BACKGROUND0_H_

#include <gba_types.h>

#include "palette/palette.h"

/*!
 * This will hold my configuration helpers for background 0
 */

u16 BG0GetMode();
void BG0LoadPalettes(palette_t* paPalettes, u32 count);

#endif//__BACKGROUND0_H_