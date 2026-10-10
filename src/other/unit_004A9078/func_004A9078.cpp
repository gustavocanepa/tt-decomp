typedef int s32;

extern "C" void func_004A59F0(void);
extern "C" s32 func_00502E70(void *);

extern "C" void func_004A9078(void *self) {
    while (func_00502E70(self) < 0) {
        func_004A59F0();
    }
}
