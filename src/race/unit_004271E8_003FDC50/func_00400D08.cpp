typedef int s32;

extern "C" s32 func_005524A8(s32 arg0, s32 arg1);
extern "C" s32 func_00400CF0(s32 arg0);

extern "C" s32 func_00400D08(s32 arg0, s32 arg1) {
    return func_005524A8(arg0, func_00400CF0(arg1));
}
