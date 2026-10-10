typedef int s32;

struct S { char pad[0x4C]; void *unk4C; };

extern "C" void func_0050E1A8(struct S *arg0);
extern "C" char D_005D7358;

extern "C" void func_00560010(struct S *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk4C = &D_005D7358;
    if (arg1) {
        func_0050E1A8(arg0);
        return;
    }
}
