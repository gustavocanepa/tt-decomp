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

extern char D_005F03A0[];
extern "C" void func_001EEDE8(void *);
extern "C" void func_001EEB30(s32, void *);
extern "C" void func_001EDBE0(void *, s32);
extern "C" void func_004AC580(void *, s32);
extern "C" void func_00282A60(void *, void *, s32);
extern "C" void func_001E3970(void *, s32);
extern "C" void func_001E5440(void *, s32);

extern "C" void func_00282E70(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    func_001EEDE8(buf0);
    func_001EEB30(buf0[0], &D_005F03A0);
    func_001EDBE0(buf0, 0x2);
    if (arg2 != 0) {
        func_004AC580((char *)arg0 + 0xE8, *(s32 *)((char *)arg0 + 0x114));
        func_00282A60(arg0, arg1, 0);
    }
    *(s32 *)((char *)arg0 + 0x128) = 0;
    func_001E3970(arg1, 0x1);
    func_001E5440(arg1, 0);
}
