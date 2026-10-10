typedef int s32;

struct Obj002768A8 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_004BA568(s32 arg0);

extern "C" s32 func_00216730(struct Obj002768A8 *arg0) {
    return func_004BA568(arg0->unk10 - 1);
}
