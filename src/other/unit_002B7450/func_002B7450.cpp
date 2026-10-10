typedef int s32;

extern "C" void func_0029BD98(s32 arg0, s32 *arg1);
extern "C" int func_002B73D8(int arg0);

extern "C" void func_002B7450(s32 arg0) {
    s32 s0 = arg0;
    s32 local = func_002B73D8(1);
    func_0029BD98(s0, &local);
}
