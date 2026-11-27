#include "types.h"

extern "C" void func_00460958(char *arg0);
extern char D_00603D60[];

extern "C" void func_0045F170(char *arg0) {
    s32 one = 1;
    s32 idx = *(s32 *)(arg0 + 0x44);
    s32 sel = idx >= 2 ? one : idx;
    func_00460958(D_00603D60 + (sel << 6));
}
