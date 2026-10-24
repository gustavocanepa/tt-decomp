#include "types.h"
extern "C" void *func_00400D68(s32 *arg0);
extern "C" void func_003F8170(char *arg0);
extern "C" char D_005D8B88[];

extern "C" void func_003F8548(void *arg0) {
    func_00400D68((s32 *)arg0);
    *(void **)((char *)arg0 + 0x0) = D_005D8B88;

    char *p = (char *)arg0 + 0x4;
    for (s32 i = 767; i != -1; i--) {
        func_003F8170(p);
        p += 0x4;
    }

    *(s32 *)((char *)arg0 + 0xC04) = 0;
}
