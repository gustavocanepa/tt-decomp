typedef int s32;

extern "C" s32 D_00578E20;
extern char D_001007D8[];

extern "C" void func_001087B0(s32 arg0, void *arg1);

extern "C" void func_00100738(s32 arg0) {
    if (D_00578E20 == 0) {
        func_001087B0(arg0, D_001007D8);
    }
}
