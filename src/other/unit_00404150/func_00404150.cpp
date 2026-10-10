typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x1A];
    s8 unk1A;
};

extern "C" void func_00404150(Obj *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) {
        arg0->unk1A = arg2;
    }
}
