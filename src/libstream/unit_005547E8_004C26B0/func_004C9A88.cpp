typedef int s32;
typedef unsigned char u8;

struct func_004C9A88_arg0 {
    char pad0[0x4];
    u8 unk4;
    u8 unk5;
};

extern "C" u8 func_004C9A88(struct func_004C9A88_arg0 *arg0, s32 arg1) {
    u8 *p;
    s32 lim = ((s32)arg0->unk4 + 7) >> 3;
    if (arg1 >= 0 && arg1 < lim) {
        p = (u8 *)arg0 + arg1;
        return p[5];
    }
    return 0;
}
