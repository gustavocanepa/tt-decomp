typedef int s32;

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" s32 func_004DA9A0(void);

extern "C" char D_005987E0[];

extern "C" s32 func_004C0480(void) {
    s32 s1;

    func_004A4D68(D_005987E0);
    s1 = func_004DA9A0();
    func_004A4DD8(D_005987E0);
    return s1;
}
