/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" void *func_00104960(void *);
extern "C" void *func_00104AC0(void *, s32, s32, s32, s32);
extern "C" void *func_00104C88(void *);
extern "C" void *pglPushAttrib(s32);
extern "C" void *func_00470B58(f32);
extern "C" void *func_00470E60(s32);
extern "C" void *func_00473498();
extern "C" void func_00104868(void *, s32);

extern "C" void func_002D5570(char *arg0) {
    char sp[0x40];
    func_00104960(sp);
    func_00104AC0(sp, *(f32 *)(arg0 + 0xE390), *(f32 *)(arg0 + 0xE394), *(f32 *)(arg0 + 0xE398), *(f32 *)(arg0 + 0xE39C));
    pglPushAttrib(0x887);
    func_00104C88(sp);
    func_00470B58(0x0.0p+0f);
    func_00470E60(2);
    func_00470B58(1.0f);
    func_00473498();
    func_00104868(sp, 2);
}
