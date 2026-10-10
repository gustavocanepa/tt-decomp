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

extern "C" void func_0043A7E8(void *);
extern "C" void func_00439930(void *);
extern "C" void func_0043AD60(s32, void *);
extern "C" s32 exception__structor_0(s32);
extern "C" void func_00447B18(s32, s32);
extern "C" void func_0043BB88(s32, s32, s32, s32);

struct func_002151A8_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};
struct func_002151A8_v_s0 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_002151A8(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 v_s0;
    ((struct func_002151A8_arg0 *)arg0)->unkC = (s32)arg1;
    func_0043A7E8(arg1);
    func_00439930(buf0);
    func_0043AD60(((struct func_002151A8_arg0 *)arg0)->unkC, buf0);
    ((struct func_002151A8_arg0 *)arg0)->unk18 = arg2;
    if (((struct func_002151A8_arg0 *)arg0)->unk1C != 0) {
        v_s0 = exception__structor_0(0x14);
        func_00447B18(v_s0, 0x4000);
        ((struct func_002151A8_arg0 *)arg0)->unk14 = v_s0;
        v_s0 = exception__structor_0(0x19c);
        func_0043BB88(v_s0, ((struct func_002151A8_arg0 *)arg0)->unkC, 0, ((struct func_002151A8_arg0 *)arg0)->unk14);
        ((struct func_002151A8_arg0 *)arg0)->unk10 = v_s0;
        ((struct func_002151A8_v_s0 *)v_s0)->unk10 = 0;
    }
}
