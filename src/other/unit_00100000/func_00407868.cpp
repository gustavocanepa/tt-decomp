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

extern "C" void func_00407500(void);
extern "C" void func_00407548(void *, void *);
extern "C" void func_00407598(void *, void *);
extern "C" void func_004075E8(void *, void *);
extern "C" void func_00407638(void *, void *);
extern "C" void func_00407688(void *, void *);
extern "C" void func_004076D8(void *, void *);
extern "C" void func_00407728(void *, void *);
extern "C" void func_00407778(void *, void *);
extern "C" void func_004077C8(void *, void *);
extern "C" void func_00407818(void *, void *);

extern "C" void func_00407868(s32 *arg0, void *arg1) {
    func_00407500();
    func_00407548(arg0, arg1);
    func_00407598(arg0, arg1);
    func_004075E8(arg0, arg1);
    func_00407638(arg0, arg1);
    func_00407688(arg0, arg1);
    func_004076D8(arg0, arg1);
    func_00407728(arg0, arg1);
    func_00407778(arg0, arg1);
    func_004077C8(arg0, arg1);
    func_00407818(arg0, arg1);
}
