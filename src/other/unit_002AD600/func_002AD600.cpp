typedef int s32;

extern "C" s32 func_002978A0(void *arg0, s32 arg1);
extern "C" void *func_002A25F8(void *arg0);
extern char D_005C5C48[];

extern "C" s32 func_002AD600(void *arg0, s32 arg1, s32 arg2) {
    func_002A25F8(arg0);
    *(void **)((char *)arg0 + 0x4) = D_005C5C48;
    return func_002978A0((char *)arg0 + 0xC, arg2);
}
