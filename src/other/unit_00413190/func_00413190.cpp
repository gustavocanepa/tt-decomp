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

extern "C" void func_00413078(void);
extern "C" s32 func_00413248(void *);
extern "C" s32 func_004130B8(void *, s32);
extern "C" s32 func_00413120(void *, s32);
extern "C" s32 func_004130E8(void *, s32);
extern "C" s32 func_00413158(void *, s32);
extern "C" void func_004F64C4(s32, void *, s32);
extern "C" void func_00413098(void *);

extern "C" void func_00413190(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 v_s1;
    s32 t1;
    s32 t2;
    s32 t3;
    func_00413078();
    v_s1 = func_00413248(arg0);
    t1 = func_004130B8(arg0, v_s1);
    *(s32 *)(char *)t1 = (s32)arg1;
    t2 = func_00413120(arg0, v_s1);
    *(s32 *)(char *)t2 = arg2;
    t3 = func_004130E8(arg0, v_s1);
    *(s32 *)(char *)t3 = 0x1;
    func_004F64C4(func_00413158(arg0, v_s1), arg3, *(s32 *)(char *)arg0);
    func_00413098(arg0);
}
