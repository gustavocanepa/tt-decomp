typedef int s32;

extern "C" void func_00318950(void);
extern "C" void func_003189A0(void);

extern "C" void func_003189D8(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_00318950();
    }
    return func_003189A0();
}
