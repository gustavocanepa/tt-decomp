typedef int s32;

extern "C" void func_004CEDF0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DB188;

struct func_004C05B0_arg0 {
    char pad0[0x68];
    void *unk68;
};

extern "C" void func_004C05B0(struct func_004C05B0_arg0 *arg0, s32 arg1) {
    arg0->unk68 = &D_005DB188;
    func_004CEDF0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
