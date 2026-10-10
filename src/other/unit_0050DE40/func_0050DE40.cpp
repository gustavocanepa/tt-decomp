typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A4808;
extern char D_00618410[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DE40(void) {
    if (D_005A4808.unk0 == 0) {
        D_005A4808.unk0 = D_00618410;
        D_005A4808.unk4 = D_005DB838;
    }
    return &D_005A4808;
}
