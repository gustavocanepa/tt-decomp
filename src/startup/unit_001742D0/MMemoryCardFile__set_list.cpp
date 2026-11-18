#include "types.h"

extern "C" void *func_00151AE8(void *arg0, void *arg1);
extern "C" void func_00151A90(void *arg0, int arg1);
extern "C" void func_00159750(void *arg0, void *arg1);
extern "C" void func_001596F8(void *arg0, int arg1);
extern "C" int GT4MC__FileGT4GameData__loadInstance(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern char D_00520050[];
extern char D_005206C0[];

extern "C" void MMemoryCardFile__set_list(void *unused0, void *arg1, s32 arg2, void *arg3) {
    s32 buf[4];
    char *s0;
    char *v1;
    char *v0;

    func_00151AE8(buf, arg1);
    v1 = *(char **)((char *)buf[0] + 0x10);
    s0 = 0;
    if (v1 != 0) {
        v0 = *(char **)(v1 + 0x4C);
        s0 = (char *)GT4MC__FileGT4GameData__loadInstance(*(s32 *)(v0 + 4), (s32)D_00520050, 0,
                                   (s32)(v1 + *(s16 *)v0), (s32)D_005206C0, (s32)v1);
    }
    func_00151A90(buf, 2);
    if (s0 != 0 && arg2 > 0) {
        func_00159750(buf, arg3);
        *(s32 *)(s0 + 0x50) = *(s32 *)((char *)buf[0] + 0x10);
        func_001596F8(buf, 2);
    }
}
