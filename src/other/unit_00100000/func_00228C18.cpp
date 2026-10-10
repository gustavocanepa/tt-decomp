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

extern char func_00537C98[];
extern char func_0054D6E8[];
extern "C" void func_001B9AF0(void);
extern "C" s32 func_0050DB48(s32, void *, s32, void *, void *, void *);
extern "C" void func_00524D68(void *, s32);

extern "C" void func_00228C18(s32 *arg0, void *arg1) {
    s32 v_s1;
    v_s1 = 0;
    func_001B9AF0();
    if (arg1 != 0) {
        v_s1 = func_0050DB48(*(s32 *)((char *)(*(s32 *)((char *)arg1 + 0x4)) + 0x4), &func_00537C98, 0, (char *)arg1 + (s32)*(s16 *)(char *)(*(s32 *)((char *)arg1 + 0x4)), &func_0054D6E8, arg1);
    }
    if (v_s1 != 0) {
        if ((char *)arg0 + 0xD4 != (char *)(v_s1 + 0xD4)) {
            func_00524D68((char *)arg0 + 0xD4, v_s1 + 0xD4);
        }
        *(s32 *)((char *)arg0 + 0xE4) = *(s32 *)((char *)v_s1 + 0xE4);
    }
}
