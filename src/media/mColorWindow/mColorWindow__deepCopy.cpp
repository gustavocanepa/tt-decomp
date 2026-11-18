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

extern char func_00537C98[];
extern char func_0054D6E8[];
extern "C" void func_001B9AF0(void);
extern "C" s32 GT4MC__FileGT4GameData__loadInstance(s32, void *, s32, void *, void *, void *);
extern "C" void func_00524D68(void *, s32);

struct mColorWindow__virtual_08_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct mColorWindow__virtual_08_arg0 {
    char pad0[0xE4];
    s32 unkE4;
};
struct mColorWindow__virtual_08_v_s1 {
    char pad0[0xE4];
    s32 unkE4;
};

extern "C" void mColorWindow__deepCopy(s32 *arg0, void *arg1) {
    s32 v_s1;
    v_s1 = 0;
    func_001B9AF0();
    if (arg1 != 0) {
        v_s1 = GT4MC__FileGT4GameData__loadInstance(*(s32 *)((char *)(((struct mColorWindow__virtual_08_arg1 *)arg1)->unk4) + 0x4), &func_00537C98, 0, (char *)arg1 + (s32)*(s16 *)(char *)(((struct mColorWindow__virtual_08_arg1 *)arg1)->unk4), &func_0054D6E8, arg1);
    }
    if (v_s1 != 0) {
        if ((char *)arg0 + 0xD4 != (char *)(v_s1 + 0xD4)) {
            func_00524D68((char *)arg0 + 0xD4, v_s1 + 0xD4);
        }
        ((struct mColorWindow__virtual_08_arg0 *)arg0)->unkE4 = ((struct mColorWindow__virtual_08_v_s1 *)v_s1)->unkE4;
    }
}
