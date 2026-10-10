typedef int s32;

struct S0036FAB0 { char pad[0x104]; void *unk104; };

extern "C" void func_0050E1A8(struct S0036FAB0 *arg0);
extern "C" char D_005DA280;

extern "C" void func_0045D1E8(struct S0036FAB0 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk104 = &D_005DA280;
    if (arg1) {
        func_0050E1A8(arg0);
        return;
    }
}
