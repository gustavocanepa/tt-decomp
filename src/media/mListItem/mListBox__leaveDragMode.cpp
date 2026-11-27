#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00257B00(void *, void *, s32);
extern "C" s32 func_00257FA8(void *, s32);
extern "C" void func_00258010(void *, s32, s32);

struct func_00257C98_arg0 {
    char pad0[0x12C];
    s32 unk12C;
    char pad130[0x1C];
    s32 unk14C;
    char pad150[0x4];
    s32 unk154;
    char pad158[0x1C];
    s32 unk174;
};

extern "C" void mListBox__leaveDragMode(s32 *arg0, void *arg1) {
    func_00257B00(arg0, arg1, 0);
    if (((struct func_00257C98_arg0 *)arg0)->unk154 >= 0) {
        if (((struct func_00257C98_arg0 *)arg0)->unk14C != ((struct func_00257C98_arg0 *)arg0)->unk154) {
            if (func_00257FA8(arg0, ((struct func_00257C98_arg0 *)arg0)->unk154) != 0) {
                func_00258010(arg0, ((struct func_00257C98_arg0 *)arg0)->unk154, 0);
            }
            if (((struct func_00257C98_arg0 *)arg0)->unk14C >= 0) {
                func_00258010(arg0, ((struct func_00257C98_arg0 *)arg0)->unk14C, ((struct func_00257C98_arg0 *)arg0)->unk12C);
            }
            ((struct func_00257C98_arg0 *)arg0)->unk174 = 0x1;
        }
    }
    ((struct func_00257C98_arg0 *)arg0)->unk154 = -0x1;
}
