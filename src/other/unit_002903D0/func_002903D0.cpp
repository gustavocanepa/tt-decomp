typedef int s32;

extern "C" void func_0028F650(s32 *arg0, s32 arg1);

extern "C" s32 func_002903D0(s32 arg0, s32 arg1) {
    s32 local = arg1;

    func_0028F650(&local, arg0);
    return local;
}
