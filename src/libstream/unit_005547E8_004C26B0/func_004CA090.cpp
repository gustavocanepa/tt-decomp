extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C9C50(...) throw();
void func_004C9CC0(...) throw();
s32 func_00574BD0(...) throw();

extern char D_005DB328[];
struct func_004CA090_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0xBC];
    char *unkC4;
    s32 unkC8;
    s32 unkCC;
    s32 unkD0;
};

s32 func_004CA090(char *arg0) {
    char *temp_s1;

    ((struct func_004CA090_arg0 *)arg0)->unk0 = 0;
    ((struct func_004CA090_arg0 *)arg0)->unkD0 = (s32)D_005DB328;
    temp_s1 = arg0 + 0x14;
    ((struct func_004CA090_arg0 *)arg0)->unk4 = 0;
    func_00574BD0(arg0 + 8, arg0);
    ((struct func_004CA090_arg0 *)arg0)->unkCC = 0;
    func_004C9CC0(temp_s1, 0, 0, 0, 0);
    ((struct func_004CA090_arg0 *)arg0)->unkC4 = (char *) (arg0 + 0x18);
    ((struct func_004CA090_arg0 *)arg0)->unkC8 = func_004C9C50(temp_s1);
}

}
