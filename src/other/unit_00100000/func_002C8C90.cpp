typedef int s32;

extern "C" s32 func_0033B390(void *arg0);

struct Obj003C8BC0 {
    char pad0[0x447A0];
    s32 unk2EF30;
};

extern "C" s32 func_002C8C90(struct Obj003C8BC0 *arg0) {
    if (arg0->unk2EF30 != 0) {
        return 4;
    }
    return func_0033B390(arg0);
}
