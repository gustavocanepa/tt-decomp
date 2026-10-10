typedef int s32;
void func_004AC770(void *, s32);
void func_004AE9F0(void *, s32);
void func_0050E1A8(void *);
extern char D_005DB2E8[];
extern char D_005DB310[];
struct func_004CA4A0_temp_a0 {
    char pad0[0x8];
    void *unk8;
};

struct func_004CA4A0_arg0 {
    char pad0[0x3C];
    void *unk3C;
};

void func_004CA4A0(void *arg0, s32 arg1) {
    struct func_004CA4A0_temp_a0 *temp_a0;
    temp_a0 = (char *)arg0 + 0x30;
    ((struct func_004CA4A0_arg0 *)arg0)->unk3C = D_005DB2E8;
    temp_a0->unk8 = D_005DB310;
    func_004AC770(temp_a0, 0);
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
