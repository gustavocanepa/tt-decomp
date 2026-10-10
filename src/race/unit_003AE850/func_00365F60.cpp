typedef int s32;

extern "C" void func_00365FB8(void);
extern "C" void *func_0050E130(s32 size);
extern "C" void func_004F6678(void *p, s32 c, s32 n);
extern "C" s32 *D_00584418;

extern "C" void func_00365F60(s32 n) {
    func_00365FB8();
    D_00584418 = (s32 *)func_0050E130(n * 4);
    func_004F6678(D_00584418, 0, n * 4);
}
