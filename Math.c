#include <stdlib.h>
#include "Math.h"

int randomBetween(int32_t _low, uint64_t _high) {
    return rand() % ((_high - _low) + 1) + _low;
}
