typedef int s32;

extern "C" s32 func_004CA110(void *arg0, s32 arg1, s32 arg2);
extern char D_005B3E80[];

extern "C" void MenuControl__structor_0(void *arg0)
{
    (void)func_004CA110(arg0, 0, 0);
    *(void **)((char *)arg0 + 0xD0) = D_005B3E80;
}
