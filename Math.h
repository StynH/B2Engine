//
// Created by styn2 on 12/1/2019.
//

#include <SDL_config.h>
#include <stdint.h>
#include "Entity.h"
#include <stdbool.h>

#ifndef B2BSAND_MATH_H
#define B2BSAND_MATH_H

int32_t randomBetween(int32_t _low, int32_t _high);
bool intersectRect(const Position* p1, const Dimension* d1, const Position* p2, const Dimension* d2);

#endif //B2BSAND_MATH_H
