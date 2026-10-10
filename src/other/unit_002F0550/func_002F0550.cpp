typedef int s32;

extern "C" s32 func_002F0508(s32 arg0, s32 arg1);

extern "C" s32 func_002F0550(s32 arg0) {
    return func_002F0508(arg0, -1) > 0;
}
