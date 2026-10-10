typedef int s32;
void func_004AC770(void *, s32);
void func_0047E9C0(void *, s32);
void func_0050E1A8(void *);
extern char D_005DA640[];
extern char D_005DA5C8[];
void func_0047E5C0(void *arg0, s32 arg1) {
    void *temp_a0;
    temp_a0 = (char *)arg0 + 0xAC;
    *(void **)((char *)arg0 + 0xA8) = D_005DA640;
    *(void **)((char *)temp_a0 + 8) = D_005DA5C8;
    func_004AC770(temp_a0, 0);
    func_0047E9C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
