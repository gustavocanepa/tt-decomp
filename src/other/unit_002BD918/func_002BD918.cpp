typedef int s32;

extern "C" void func_002BD370(s32 arg0, void *arg1);

extern "C" void func_002BD918(void *arg0) {
    s32 *vtbl = *(s32 **)((char *)arg0 - 4);
    func_002BD370(*vtbl, arg0);
}
