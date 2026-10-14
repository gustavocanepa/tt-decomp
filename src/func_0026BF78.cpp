typedef int s32;

struct Obj {
    char pad[0x118];
    s32 unk118;
};

extern "C" void func_0026BD80(struct Obj *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0026BF78(struct Obj *arg0, s32 arg1) {
    if (arg0->unk118 != 0) {
        func_0026BD80(arg0, arg1, 1);
        return 2;
    }
    return 0;
}
