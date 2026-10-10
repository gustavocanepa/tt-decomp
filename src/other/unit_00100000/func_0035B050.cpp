typedef int s32;

extern void *D_005D1180;
extern "C" void func_0038E2B8(void *);

extern "C" void func_0035B050(void *arg0) {
    func_0038E2B8(arg0);
    *(void **)((char *)arg0 + 0x14) = &D_005D1180;
    *(float *)((char *)arg0 + 0x20) = *(float *)((char *)"GTMODE_MACHINE_TEST_MAX_SPEED" + 0x14c0);
    *(void **)((char *)arg0 + 0x1c) = 0x0;
    *(void **)((char *)arg0 + 0x18) = 0x0;
}
