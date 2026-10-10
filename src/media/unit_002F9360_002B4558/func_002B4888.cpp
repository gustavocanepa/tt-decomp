typedef int s32;

extern "C" s32 func_002978A0(void *arg0, s32 arg1);
extern "C" void *func_002B2290(void *arg0);
extern char D_005C6C88[];

struct func_002B4888_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" s32 func_002B4888(void *arg0, s32 arg1, s32 arg2) {
    func_002B2290(arg0);
    ((struct func_002B4888_arg0 *)arg0)->unk4 = D_005C6C88;
    return func_002978A0((char *)arg0 + 0xC, arg2);
}
