typedef int s32;

struct S0039A4F8 { char pad[0x1C]; void *unk1C; };

extern "C" void func_0050E1A8(struct S0039A4F8 *arg0);
extern "C" char D_005D9D48;

extern "C" void func_0042D868(struct S0039A4F8 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk1C = &D_005D9D48;
    if (arg1) {
        func_0050E1A8(arg0);
        return;
    }
}
