typedef int s32;

extern "C" void func_00417548(void *lock);
extern "C" void func_00417B40(void *lock, s32 arg);

extern char D_00769600[];

extern "C" void func_004172A8(void) {
    void *lock = D_00769600;
    if (*(volatile s32 *)lock == 0) {
        func_00417548(lock);
        func_00417B40(lock, 0);
    }
}
