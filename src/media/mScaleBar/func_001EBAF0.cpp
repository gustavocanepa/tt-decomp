#include "types.h"

extern char D_005EA3D8[];

extern "C" void func_001C0228(void *arg0, s32 arg1);
extern "C" void func_001C04F8(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4);
extern "C" void func_001E4E80(s32 arg0, void *arg1);
extern "C" void func_001EDBE0(void *arg0, s32 arg1);
extern "C" void func_001EEB30(s32 arg0, char *arg1);
extern "C" void func_001EEDE8(void *arg0);

extern "C" void func_001EBAF0(char *arg0, s32 arg1) {
    s32 buf;
    if (*(s32 *)(arg0 + 0x100) == 0) {
        func_001EEDE8(&buf);
        func_001EEB30(buf, D_005EA3D8);
        func_001EDBE0(&buf, 2);
    }
    char *v = arg0 + 0x120;
    if (*(s32 *)v != 0) {
        func_001C04F8(&buf, v, 2, arg1, arg0);
        func_001E4E80(arg1, &buf);
        func_001C0228(&buf, 2);
    }
}
