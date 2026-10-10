typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

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

extern char D_0076FCC0[];
extern char D_0076FCE0[];
extern "C" void func_0047D690(void);
extern "C" void func_004BEC28(s32, s32, s32);
extern "C" void func_004BEC58(s32);
extern "C" void func_004AD9B8(void *, s32);

struct func_004806B0_arg1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

struct func_004806B0_v_s0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_004806B0(s32 *arg0, struct func_004806B0_arg1 *arg1) {
    s32 v_s0;
    func_0047D690();
    v_s0 = arg1->unkC;
    if (v_s0 != 0) {
        if (*(s32 *)((char *)(arg1->unk4) + 0x74) == 0x1) {
            if (((struct func_004806B0_v_s0 *)v_s0)->unk8 != 0) {
                func_004BEC28(*(s32 *)(char *)v_s0, ((struct func_004806B0_v_s0 *)v_s0)->unkC, (0x40 - ((struct func_004806B0_v_s0 *)v_s0)->unk8));
            }
        }
        func_004BEC58(*(s32 *)(char *)v_s0);
        func_004AD9B8(&D_0076FCE0, ((struct func_004806B0_v_s0 *)v_s0)->unkC);
        func_004AD9B8(&D_0076FCC0, v_s0);
        arg1->unkC = 0;
    }
    return 0;
}
