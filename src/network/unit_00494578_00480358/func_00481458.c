typedef int s32;
void func_004AC770(void *, s32);
void func_0047CAD0(void *, s32);
void func_0050E1A8(void *);
extern char D_005DAA30[];
extern char D_005DA5C8[];
void func_00481458(void *arg0, s32 arg1) {
    void *temp_a0;
    temp_a0 = (char *)arg0 + 0xA8;
    *(void **)((char *)arg0 + 0xA4) = D_005DAA30;
    *(void **)((char *)temp_a0 + 8) = D_005DA5C8;
    func_004AC770(temp_a0, 0);
    func_0047CAD0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
