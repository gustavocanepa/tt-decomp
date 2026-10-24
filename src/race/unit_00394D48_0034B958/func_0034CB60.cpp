#include "types.h"

extern "C" void func_0034DC08(void *self, f32 f);
extern "C" void ModelSet2__render(s32 a0, s32 a1);
extern "C" void func_00470450(s32 a0);
extern "C" void func_00470B48(s32 a0);
extern "C" void func_00470E60(s32 a0);
extern "C" void func_00473178(s32 a0);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void pglPushAttrib(s32 a0);
extern "C" void func_00473498(void);
extern "C" void func_0047525C(f32 *a0);
extern "C" void func_004752F8(f32 *a0);

extern "C" void func_0034CB60(char *arg0) {
    f32 buf[16];
    if (*(s32 *)(arg0 + 0x58) != 0) {
        pglPushAttrib(0x40);
        func_00470450((s32)0xFF000000U);
        func_00470B48(0);
        func_00470E60(3);
        func_00470450(-1);
        func_0034DC08(*(char **)(arg0 + 0x80) + 0x60, 1.0f);
        func_00473178(1);
        func_00473050();
        func_004752F8(buf);
        buf[14] = buf[14] * 100.0f;
        func_0047525C(buf);
        func_00473178(0);
        ModelSet2__render(*(s32 *)(arg0 + 0x58), 0);
        func_00473178(1);
        func_004730A8();
        func_00473178(0);
        func_00473498();
    }
}
