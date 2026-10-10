typedef int s32;

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A47B0;
extern char D_006183B8[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DBD8(void) {
    if (D_005A47B0.unk0 == 0) {
        D_005A47B0.unk0 = D_006183B8;
        D_005A47B0.unk4 = D_005DB838;
    }
    return &D_005A47B0;
}
