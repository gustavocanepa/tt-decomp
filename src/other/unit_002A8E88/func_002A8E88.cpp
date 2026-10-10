typedef int s32;

extern char D_0057C610[];

extern "C" void func_002A8CF8(s32 arg0, void *arg1, void *arg2);

extern "C" void func_002A8E88(void *arg0, void *arg1, s32 *arg2) {
    func_002A8CF8(*arg2, arg1, D_0057C610);
}
