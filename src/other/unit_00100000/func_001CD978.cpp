typedef int s32;

struct S0021A728 { char pad[0x48]; void *unk48; };

extern "C" void func_0050E1A8(struct S0021A728 *arg0);
extern "C" char D_005AFA98;

extern "C" void func_001CD978(struct S0021A728 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk48 = &D_005AFA98;
    if (arg1) {
        func_0050E1A8(arg0);
        return;
    }
}
