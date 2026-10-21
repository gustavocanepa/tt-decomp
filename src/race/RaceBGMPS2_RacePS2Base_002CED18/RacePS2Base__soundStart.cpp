#include "types.h"

extern "C" void func_0033C660(void *arg0);
extern "C" void RaceCourseSound__playStart(s32 *arg0);
extern "C" void func_0039D148(void *arg0);

extern "C" void RacePS2Base__soundStart(void *arg0) {
    func_0033C660(arg0);
    RaceCourseSound__playStart((s32 *)((char *)arg0 + 0xE220));
    func_0039D148((char *)arg0 + 0x36C0);
}
