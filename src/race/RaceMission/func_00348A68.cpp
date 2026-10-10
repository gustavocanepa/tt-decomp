typedef int s32;

extern "C" void RaceBasic__cleanup(void);
extern "C" void func_0033E078(void *arg0, s32 arg1);

extern "C" void func_00348A68(void *arg0) {
    void *s0 = arg0;
    RaceBasic__cleanup();
    func_0033E078(s0, 0);
}
