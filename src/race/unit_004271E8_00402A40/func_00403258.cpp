typedef int s32;
typedef unsigned int u32;

extern char D_005FA5A0[];
extern char D_005FA5B0[];
extern "C" int func_004A8268(void *a, const char *b);
extern "C" void func_00403DC0(char *a, s32 b, s32 c);
extern "C" void func_00404150(char *a, s32 b, s32 c);
extern "C" void func_00404540(char *a, s32 b, s32 c);
extern "C" void func_004049A0(s32 a, u32 b, s32 c);

extern "C" void func_00403258(char *self, s32 arg1, s32 arg2) {
    if (func_004A8268((void *)arg1, D_005FA5A0) == 0) {
        return func_00403DC0(self + 0x18, 0, arg2);
    }
    if (func_004A8268((void *)arg1, D_005FA5B0) == 0) {
        func_00404150(self + 0x48, 0, arg2);
        func_00404540(self + 0x64, 0, arg2);
        return func_004049A0((s32)(self + 0x8C), 0, arg2);
    }
}
