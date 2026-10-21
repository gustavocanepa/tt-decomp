#include "types.h"

extern char D_005C9850[];

extern "C" s32 func_00318418(void *);
extern "C" void *func_0031AC18(void *);
extern "C" s32 func_003209C0(void *, s32);
extern "C" void func_0032D710(void *);
extern "C" void func_0032D8C8(void *);
extern "C" s32 exception__structor_0(s32);

static inline s32 make_camera() {
    s32 p = exception__structor_0(0x200);
    func_0032D710((void *)p);
    return p;
}
static inline s32 make_other() {
    s32 p = exception__structor_0(0x1C0);
    func_0032D8C8((void *)p);
    return p;
}
extern "C" s32 func_00320878(void *arg0) {
    char *p2 = (char *)arg0 + 0xD00;
    s32 s0;
    func_0031AC18(arg0);
    *(char **)arg0 = D_005C9850;
    func_00318418((char *)arg0 + 0xF00);
    s0 = make_camera();
    *(s32 *)p2 = s0;
    s0 = make_other();
    *(s32 *)((char *)arg0 + 0xD04) = s0;
    return func_003209C0(arg0, 0);
}
