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

extern "C" void func_00257B00(void *, void *, s32);
extern "C" s32 func_00257FA8(void *, s32);
extern "C" void func_00258010(void *, s32, s32);

extern "C" void func_00257C98(s32 *arg0, void *arg1) {
    func_00257B00(arg0, arg1, 0);
    if (*(s32 *)((char *)arg0 + 0x154) >= 0) {
        if (*(s32 *)((char *)arg0 + 0x14C) != *(s32 *)((char *)arg0 + 0x154)) {
            if (func_00257FA8(arg0, *(s32 *)((char *)arg0 + 0x154)) != 0) {
                func_00258010(arg0, *(s32 *)((char *)arg0 + 0x154), 0);
            }
            if (*(s32 *)((char *)arg0 + 0x14C) >= 0) {
                func_00258010(arg0, *(s32 *)((char *)arg0 + 0x14C), *(s32 *)((char *)arg0 + 0x12C));
            }
            *(s32 *)((char *)arg0 + 0x174) = 0x1;
        }
    }
    *(s32 *)((char *)arg0 + 0x154) = -0x1;
}
