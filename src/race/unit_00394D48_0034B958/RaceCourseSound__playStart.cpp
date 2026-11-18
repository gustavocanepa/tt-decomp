#include "types.h"

extern "C" void RaceCourseSound__playStart(s32 *arg0) {
    if (*arg0 == 0) {
        *arg0 = 1;
    }
}
