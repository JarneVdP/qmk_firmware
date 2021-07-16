#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K00, K01, \
	K10, K11, \
	K20, K21, K32  \
) { \
	{ K00,   K01 }, \
	{ K10,   K11 }, \
	{ K20,   K21 , K32}  \
}

#endif