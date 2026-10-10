typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A47F8;
extern char D_00618400[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DDD0(void) {
    if (D_005A47F8.unk0 == 0) {
        D_005A47F8.unk0 = D_00618400;
        D_005A47F8.unk4 = D_005DB838;
    }
    return &D_005A47F8;
}
