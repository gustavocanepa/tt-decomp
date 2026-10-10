typedef int s32;
void func_004887E0(void *a, s32 b);
s32 func_0048B560(void *a, s32 b);
void func_0048B5E8(void *a, s32 b, s32 c);
void func_0050E1A8(void *a);
extern char D_005DAB58[];
void func_0048B4D8(char *arg0, s32 arg1) {
    s32 temp_v0;

    *(char **)(arg0 + 0x78) = D_005DAB58;
    temp_v0 = func_0048B560(arg0, 1);
    if (temp_v0 > 0) {
        func_0048B5E8(arg0, 1, temp_v0 | 0x8000);
    }
    func_004887E0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
