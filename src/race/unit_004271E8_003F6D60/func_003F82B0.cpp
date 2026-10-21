typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[2];
    u8 unk2;
};

extern "C" s32 func_003F82B0(Obj *arg0, s32 arg1) {
    if (arg1 >= 0xFF) {
        arg1 = 0xFF;
    }
    if (arg0->unk2 < (u8)arg1) {
        arg0->unk2 = (u8)arg1;
        return 1;
    }
    return 0;
}
