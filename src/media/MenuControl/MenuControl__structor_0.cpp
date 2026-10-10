typedef int s32;

extern "C" s32 func_004CA110(void *arg0, s32 arg1, s32 arg2);
extern char D_005B3E80[];

struct MenuControl__structor_0_arg0 {
    char pad0[0xD0];
    void *unkD0;
};

extern "C" void MenuControl__structor_0(struct MenuControl__structor_0_arg0 *arg0)
{
    (void)func_004CA110(arg0, 0, 0);
    arg0->unkD0 = D_005B3E80;
}
