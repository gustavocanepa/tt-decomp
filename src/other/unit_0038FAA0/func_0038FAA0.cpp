typedef int s32;

extern const char **D_00584418;
extern char D_005F78F8[];
extern "C" s32 func_004A6500(char *, const char *, s32, const char *);

extern "C" void func_0038FAA0(char *buf, s32 unused, s32 n) {
    s32 idx = (n != 1) ? 0x4F : 0x4E;
    func_004A6500(buf, D_005F78F8, n, D_00584418[idx]);
}
