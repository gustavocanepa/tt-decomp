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

extern "C" void func_00468C80(void *);
extern "C" s32 func_00104E18(void *);
extern "C" void func_00468CA8(void *, s32, s32, s32, s32);
extern "C" void func_00468F10(void *, s32, s32);
extern "C" void func_00469158(void *, s32, s32, s32);
extern "C" void func_00468FE0(void *, s32, s32);

extern "C" void func_00104F18(s32 *arg0, void *arg1) {
    func_00468C80(arg1);
    func_00468CA8(arg1, 0, *(s32 *)(char *)arg0, *(s32 *)((char *)arg0 + 0x4), func_00104E18(arg0));
    func_00468F10(arg1, *(s32 *)((char *)arg0 + 0x18), *(s32 *)((char *)arg0 + 0x1c));
    func_00469158(arg1, 0, *(s32 *)((char *)arg0 + 0x10), (*(s32 *)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x18)) - 0x1);
    func_00469158(arg1, 0x1, *(s32 *)((char *)arg0 + 0x14), (*(s32 *)((char *)arg0 + 0x14) + *(s32 *)((char *)arg0 + 0x1c)) - 0x1);
    func_00468FE0(arg1, 0x4, 0x2);
    func_00468FE0(arg1, 0x5, 0x2);
}
