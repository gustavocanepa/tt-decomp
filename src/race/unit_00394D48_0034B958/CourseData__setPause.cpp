#include "types.h"

extern f32 D_00584064;

extern "C" void CourseData__evalVMMethods(void *self, s32 on);

extern "C" void CourseData__setPause(void *self, s32 on) {
    if (on) {
        D_00584064 = 0.0f;
        return CourseData__evalVMMethods(self, on);
    }
    D_00584064 = 1.0f / 60.0f;
}
