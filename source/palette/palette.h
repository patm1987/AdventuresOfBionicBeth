
#ifndef __PALETTE_H_
#define __PALETTE_H_

#define PALETTE_COLOR_COUNT 16
#define PALETTE_COLOR_TRANSPARENT 0

#include <gba_types.h>

typedef struct {
	u16 colors [PALETTE_COLOR_COUNT];
} palette_t;

#endif//__PALETTE_H_
