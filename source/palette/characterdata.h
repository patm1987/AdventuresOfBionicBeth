#ifndef __CHARACTERDATA_H_
#define __CHARACTERDATA_H_

#include <gba_types.h>

#define CHAR_WIDTH 8
#define CHAR_HEIGHT 8
#define CHAR_DEPTH 4
#define BITS_PER_BYTE 8

typedef struct {
	// a basic character is 8x8 dots with 4 bits per dot
	// 8 * 8 * (4 / 8) -> 16 / 2 -> 8
	u8 data[CHAR_WIDTH * CHAR_HEIGHT * CHAR_DEPTH / BITS_PER_BYTE];
} basic_character_t;

void CHSetDot(basic_character_t* pChar, u32 x, u32 y, u8 data);

#endif//__CHARACTERDATA_H_