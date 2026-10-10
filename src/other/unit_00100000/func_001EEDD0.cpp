typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00266478(s32 arg0);

extern "C" s32 func_001EEDD0(Obj *arg0) {
    return func_00266478(arg0->unk14);
}
