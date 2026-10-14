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

extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_001D0060(void *, void *);
extern "C" void func_001D0008(void *, s32);

struct func_001D0660_v_s0 {
    char pad0[0x1E8];
    s32 unk1E8;
};

extern "C" void func_001D0660(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    v_s1 = 0x1;
    if (arg2 > 0) {
        func_0029CF48(buf0, arg3);
        v_s1 = func_0029E9F0(buf0[0]) != 0;
        func_0029CEF0(buf0, 0x2);
    }
    func_001D0060(buf0, arg1);
    ((struct func_001D0660_v_s0 *)buf0[0])->unk1E8 = v_s1;
    func_001D0008(buf0, 0x2);
}
