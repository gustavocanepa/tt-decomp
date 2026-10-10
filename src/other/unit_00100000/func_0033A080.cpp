typedef int s32;

struct Obj {
    char pad[0xD94];
    s32 unkCD0;
};

extern s32 D_00583FD0;

extern "C" void func_0033A080(Obj *arg0, s32 arg1) {
    arg0->unkCD0 = arg1;
    D_00583FD0 = arg1;
}
