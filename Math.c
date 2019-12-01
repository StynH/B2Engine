#include <stdlib.h>
#include "Math.h"
#include "Entity.h"

int randomBetween(int32_t _low, uint64_t _high) {
    return rand() % ((_high - _low) + 1) + _low;
}

bool intersectRect(const Position* p1, const Dimension* d1, const Position* p2, const Dimension* d2) {
    return !(p2->x > p1->x + d1->width  ||
             p2->x + d2->width < p1->x  ||
             p2->y > p1->y + d1->height ||
             p2->y + d2->height < p1->y);
}