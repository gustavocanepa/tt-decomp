typedef int s32;

extern s32 func_00408B58(s32 a);
extern s32 func_0040D280(s32 a);

struct func_001321B0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_001321B0(void *arg0) {
    return func_0040D280(func_00408B58(((struct func_001321B0_arg0 *)arg0)->unk14));
}
