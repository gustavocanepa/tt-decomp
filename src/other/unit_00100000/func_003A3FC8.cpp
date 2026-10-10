typedef int s32;
typedef unsigned char u8;

struct Obj_003F69C8 {
    u8 pad0[0x5D6];
    u8 unk5B6;
};

extern "C" s32 func_002FB6B8(void *arg0, struct Obj_003F69C8 *arg1);
extern "C" s32 func_00305C78(struct Obj_003F69C8 *arg0);

extern "C" s32 func_003A3FC8(void *arg0, struct Obj_003F69C8 *arg1) {
    if (arg1->unk5B6 != 0) {
        return func_00305C78(arg1);
    }
    return func_002FB6B8(arg0, arg1);
}
