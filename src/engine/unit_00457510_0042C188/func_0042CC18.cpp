#include "types.h"

extern "C" unsigned int func_004A8368(const char *);
extern "C" void func_0042C978();
extern "C" s32 func_0042C728(const char *);

extern "C" s32 func_0042CC18(const char *s) {
    s32 r;
    if (!s || !func_004A8368(s)) {
        func_0042C978();
        r = -1;
    } else {
        r = func_0042C728(s);
    }
    return r;
}
