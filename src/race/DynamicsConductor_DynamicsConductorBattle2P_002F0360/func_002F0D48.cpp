#include "types.h"

extern "C" s32 DynamicsConductor__getCourseType(void);

extern "C" s32 func_002F0D48(void) {
    return DynamicsConductor__getCourseType() == 1;
}
