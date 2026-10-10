typedef int s32;

extern s32 func_00408B58(s32 a);
extern s32 func_0040CE70(s32 a);

struct func_00132190_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00132190(void *arg0) {
    return func_0040CE70(func_00408B58(((struct func_00132190_arg0 *)arg0)->unk14));
}
