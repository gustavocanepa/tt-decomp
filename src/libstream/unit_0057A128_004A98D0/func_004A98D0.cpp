#include "types.h"

struct Obj {
    s64 unk0;
    char pad[0x8 - 8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_004A98D0(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk8 = 0x67452301;
    arg0->unkC = 0xEFCDAB89;
    arg0->unk10 = 0x98BADCFE;
    arg0->unk14 = 0x10325476;
}
