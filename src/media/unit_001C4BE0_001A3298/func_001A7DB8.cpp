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

extern char D_00579534[];
extern "C" void func_00470B48(s32);
extern "C" void func_00470450(s32);
extern "C" void func_00104C88(void *);
extern "C" void func_00470E60(s32);

struct func_001A7DB8_v_s0 {
    char pad0[0x78];
    s32 unk78;
};

extern "C" void func_001A7DB8(s32 *arg0) {
    char *v_s0;
    s32 v_s1;
    v_s0 = (char *)&D_00579534;
    func_00470B48(0);
    v_s1 = 0x1;
    func_00470450(-0x1);
    func_00104C88((char *)v_s0 + (((((struct func_001A7DB8_v_s0 *)v_s0)->unk78 << 4) - ((struct func_001A7DB8_v_s0 *)v_s0)->unk78) << 2));
    func_00470E60(0x1);
    func_00104C88((char *)v_s0 + ((((v_s1 - ((struct func_001A7DB8_v_s0 *)v_s0)->unk78) << 4) - (v_s1 - ((struct func_001A7DB8_v_s0 *)v_s0)->unk78)) << 2));
    func_00470E60(0x1);
    *(s32 *)((char *)v_s0 + (((((struct func_001A7DB8_v_s0 *)v_s0)->unk78 << 4) - ((struct func_001A7DB8_v_s0 *)v_s0)->unk78) << 2) + 0x30) = 0;
    v_s1 = (v_s1 - ((struct func_001A7DB8_v_s0 *)v_s0)->unk78);
    *(s32 *)((char *)v_s0 + (((v_s1 << 4) - v_s1) << 2) + 0x30) = 0;
}
