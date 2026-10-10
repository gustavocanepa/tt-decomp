typedef int s32;

extern "C" s32 func_00366130(s32 arg0);

extern "C" s32 func_0037A020(s32 arg0) {
    s32 temp = func_00366130(arg0);
    return (temp == 0) ? arg0 : temp;
}
