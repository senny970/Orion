#pragma once

//#include "../CSX/CSX.h"




#define GLOBAL_VARS_PATTERN "\xA1\x00\x00\x00\x00\x8B\x4D\xFC\x8B\x55\x08"
#define GLOBAL_VARS_MASK "x????xxxxxx"

#define CLIENT_MODE_PATTERN "\xB9\x00\x00\x00\x00\x83\x38\x02\x75\x0D\xFF\xB0\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x5D\xC3"
#define CLIENT_MODE_MASK "x????xxxxxxx????x????xx"

