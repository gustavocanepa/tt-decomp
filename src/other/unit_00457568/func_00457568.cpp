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

extern "C" void func_0045A3A8(void *, s32);
extern "C" void func_0045A330(void *, s32);

extern "C" void func_00457568(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    char *v_s0;
    v_s0 = (char *)arg0 + 0x85c;
    func_0045A3A8(v_s0, (0 | 0xffc0));
    func_0045A3A8(v_s0, 0x11);
    func_0045A330(v_s0, *(s32 *)((char *)arg1 + 0xc));
    func_0045A3A8(v_s0, *(s32 *)((char *)arg1 + 0x4));
    func_0045A3A8(v_s0, *(s32 *)(char *)arg1);
    func_0045A330(v_s0, 0x3);
    func_0045A330(v_s0, 0);
    func_0045A330(v_s0, ((*(s32 *)(char *)arg2 << 4) | *(s32 *)((char *)arg2 + 0x4)));
    func_0045A330(v_s0, *(s32 *)(char *)arg3);
    func_0045A330(v_s0, 0x1);
    func_0045A330(v_s0, ((*(s32 *)((char *)arg2 + 0x8) << 4) | *(s32 *)((char *)arg2 + 0xc)));
    func_0045A330(v_s0, *(s32 *)((char *)arg3 + 0x4));
    func_0045A330(v_s0, 0x2);
    func_0045A330(v_s0, ((*(s32 *)((char *)arg2 + 0x10) << 4) | *(s32 *)((char *)arg2 + 0x14)));
    func_0045A330(v_s0, *(s32 *)((char *)arg3 + 0x8));
}
