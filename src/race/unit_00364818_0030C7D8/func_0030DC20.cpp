typedef short s16;
typedef unsigned char u8;

struct Obj {
    char pad0[0x4CC];
    s16 unk4AC;
    char pad4AE[0x4D0 - 0x4CC - 2];
    u8 unk4B0;
    char pad4B1[1];
    u8 unk4B2;
};

extern "C" int func_0030DC20(Obj *arg0) {
    int var_v1;

    var_v1 = arg0->unk4AC;
    if (arg0->unk4B2 == 0) {
        var_v1 -= arg0->unk4B0;
    }
    return var_v1;
}
