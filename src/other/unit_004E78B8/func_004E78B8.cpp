typedef int s32;

extern "C" s32 func_004E78D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern "C" s32 func_004E78B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_004E78D0(arg0, arg1, arg2, arg3, arg4, 0);
}
