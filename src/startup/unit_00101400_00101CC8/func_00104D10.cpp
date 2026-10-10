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

extern "C" void func_0046D8E8(void);
extern "C" void func_00472628(void);
extern "C" s32 func_00104E18(void *);
extern "C" void func_00471E18(s32, s32, s32, s32);
extern "C" void func_00472130(s32, s32);
extern "C" void func_00472528(s32, s32, s32);
extern "C" void func_00472268(s32, s32);

extern "C" void func_00104D10(s32 *arg0) {
    func_0046D8E8();
    func_00472628();
    func_00471E18(0, *(s32 *)(char *)arg0, *(s32 *)((char *)arg0 + 0x4), func_00104E18(arg0));
    func_00472130((*(s32 *)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x18)), (*(s32 *)((char *)arg0 + 0x14) + *(s32 *)((char *)arg0 + 0x1c)));
    func_00472528(0, 0, (*(s32 *)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x18)) - 0x1);
    func_00472528(0x1, 0, (*(s32 *)((char *)arg0 + 0x14) + *(s32 *)((char *)arg0 + 0x1c)) - 0x1);
    func_00472268(0x4, 0x2);
    func_00472268(0x5, 0x2);
    func_00472268(0x1, 0);
    func_00472268(0x7, 0);
}
