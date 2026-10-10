typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 NormalCarGeometry__getSeatZ(Obj *arg0, s32 arg1);

extern "C" s32 func_00341D90(Obj *arg0) {
    return NormalCarGeometry__getSeatZ(arg0, arg0->unk4 != 0);
}
