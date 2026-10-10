typedef int s32;

extern "C" s32 func_0026AA18(s32 arg0, s32 arg1);
extern "C" void func_00202758(s32 arg0, s32 *arg1);

extern "C" s32 func_0026C4B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 resultLocal;
    s32 zeroLocal;
    s32 result = func_0026AA18(arg1, arg2);

    if (result != 0) {
        resultLocal = result;
        func_00202758(arg0, &resultLocal);
    } else {
        zeroLocal = 0;
        func_00202758(arg0, &zeroLocal);
    }

    return arg0;
}
