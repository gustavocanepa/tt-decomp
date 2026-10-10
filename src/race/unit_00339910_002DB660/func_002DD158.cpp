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

extern char D_005F2AF8[];
extern "C" void func_00424178(void *, void *, void *);
extern "C" void func_00423BB0(void *, s32);
extern "C" void GT4Model__BinStreamWriter__writeArray(void *, void *, s32);
extern "C" void func_004241E8(void *, void *);

extern "C" void func_002DD158(s32 *arg0, void *arg1) {
    s32 buf0[4];
    func_00424178(buf0, arg1, &D_005F2AF8);
    func_00423BB0(arg1, 0x1);
    GT4Model__BinStreamWriter__writeArray(arg1, arg0, 0x24);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x24, 0x10);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x34, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x38, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x3c, 0x4);
    GT4Model__BinStreamWriter__writeArray(arg1, (char *)arg0 + 0x40, 0x4);
    func_004241E8(buf0, arg1);
}
