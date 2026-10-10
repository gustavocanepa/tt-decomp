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

extern "C" void func_004A4D68(void *);
extern "C" void func_004AC9B8(void *, void *);
extern "C" void func_004AC838(void *, void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004AEB30(void *);

extern "C" void func_0047CED8(s32 *arg0, void *arg1) {
    char *v_s3;
    char *v_s2;
    v_s3 = (char *)arg0 + 0x10;
    v_s2 = (char *)arg1 + 0x3c;
    func_004A4D68(v_s3);
    func_004AC9B8((char *)arg0 + 0x40, v_s2);
    func_004A4D68(arg1);
    *(s32 *)((char *)arg1 + 0x80) = 0x1;
    func_004AC838((char *)arg0 + 0x4c, v_s2);
    func_004A4DD8(arg1);
    func_004AEB30((char *)arg0 + 0x64);
    func_004A4DD8(v_s3);
}
