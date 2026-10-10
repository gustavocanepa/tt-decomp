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

extern "C" s32 func_004806B0(s32 *arg0, void *arg1) {
    s32 v_s0;
    func_0047D690();
    v_s0 = *(s32 *)((char *)arg1 + 0xc);
    if (v_s0 != 0) {
        if (*(s32 *)((char *)(*(s32 *)((char *)arg1 + 0x4)) + 0x74) == 0x1) {
            if (*(s32 *)((char *)v_s0 + 0x8) != 0) {
                func_004BEC28(*(s32 *)(char *)v_s0, *(s32 *)((char *)v_s0 + 0xc), (0x40 - *(s32 *)((char *)v_s0 + 0x8)));
            }
        }
        func_004BEC58(*(s32 *)(char *)v_s0);
        func_004AD9B8(&D_0076FCE0, *(s32 *)((char *)v_s0 + 0xc));
        func_004AD9B8(&D_0076FCC0, v_s0);
        *(s32 *)((char *)arg1 + 0xc) = 0;
    }
    return 0;
}
