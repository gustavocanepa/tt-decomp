typedef int s32;

extern "C" s32 func_002E86D0(s32 arg0);

extern "C" s32 func_002E86F8(s32 arg0, s32 arg1) {
    return func_002E86D0(arg0) + (arg1 << 16);
}
