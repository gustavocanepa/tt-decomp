typedef int s32;
void func_004AC770(void *, s32);
void func_004AE9F0(void *, s32);
void func_0050E1A8(void *);
extern char D_005DB2E8[];
extern char D_005DB310[];
void func_004CA4A0(void *arg0, s32 arg1) {
    void *temp_a0;
    temp_a0 = (char *)arg0 + 0x30;
    *(void **)((char *)arg0 + 0x3C) = D_005DB2E8;
    *(void **)((char *)temp_a0 + 8) = D_005DB310;
    func_004AC770(temp_a0, 0);
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
