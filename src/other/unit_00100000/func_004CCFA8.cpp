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

extern s32 D_005A0800;
extern s32 D_005A0804;
extern s32 D_005A0808;
extern char D_005A080C[];
extern "C" s32 func_004CC568(s32);
extern "C" void func_004CC668(s32);

extern "C" void func_004CCFA8(s32 *arg0) {
    char *v_s0;
    s32 t1;
    s32 v_s1;
    s32 v_s0_s32;
    v_s0 = (char *)&D_005A080C;
    D_005A0808 = 0x1;
    func_004CC568(0x8);
    t1 = func_004CC568(0x1);
    *(s32 *)(char *)v_s0 = t1;
    func_004CC568(0x2);
    v_s1 = func_004CC568(0x2);
    v_s0_s32 = func_004CC568(0x2);
    func_004CC568(0xc);
    func_004CC668(0x1);
    func_004CC568(0x8);
    func_004CC568(0x1);
    func_004CC568(0x2);
    func_004CC568(0x5);
    v_s1 = (v_s1 << 12);
    v_s0_s32 = (v_s0_s32 << 12);
    v_s1 = (v_s1 | (D_005A0800 & 0xfff));
    v_s0_s32 = (v_s0_s32 | (D_005A0804 & 0xfff));
    *(s32 *)(char *)&D_005A0800 = v_s1;
    *(s32 *)(char *)&D_005A0804 = v_s0_s32;
}
