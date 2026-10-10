typedef int s32;

extern "C" s32 func_002FB6A8(s32 **arg0);

extern "C" s32 func_003A3FF8(s32 **arg0) {
    s32 result = func_002FB6A8(arg0);
    return (result < 4) ? result : 0;
}
