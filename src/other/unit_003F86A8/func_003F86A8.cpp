typedef int s32;

extern "C" s32 func_003F86D8(s32 arg0, s32 arg1);
extern "C" s32 func_00410340(s32 arg0);

extern "C" s32 func_003F86A8(s32 arg0, s32 arg1) {
    return func_003F86D8(arg0, func_00410340(arg1));
}
