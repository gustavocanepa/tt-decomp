typedef int s32;

struct Obj {
    char pad[0x4C];
    s32 unk4C;
};

extern "C" s32 func_0040F578(s32 arg0, void *buf);
extern "C" void func_00412B70(Obj *arg0, void *buf);

extern "C" s32 func_00412B20(Obj *arg0, s32 arg1) {
    char buf[0x20];

    if (func_0040F578(arg1, buf)) {
        arg0->unk4C = arg1;
        func_00412B70(arg0, buf);
        return 1;
    }
    return 0;
}
